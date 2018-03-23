//c, c++
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//cigcc
#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>

//mysql
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using namespace std;
using namespace cgicc;
using namespace sql;

#define S	 					cout << 
#define E  					<< endl;

string SERVER, USER, PASSWORD, DATABASE;
			
Driver *driver;
Connection *con;
Statement *stmt;
PreparedStatement *pstmt;
ResultSet *res;

int main()
{

S HTTPHTMLHeader() E

S html() E
		S head() E
			S title("SignUp Page") E
			S meta().set("charset", "UTF-8") E
			S meta().set("name", "viewport").set("content", "width=device-width, initial-scale=1.0") E
			S cgicc::link().set("rel", "icon").set("href", "http://strongwow.ir/media/tabicon.png") E
			S cgicc::link().set("rel", "stylesheet").set("href", "http://strongwow.ir/styles.css") E
		S head() E
		S body() E
			S cgicc::div() E
				S form().set("action", "signUpSubmit.cgi").set("method", "post").set("autocomplete", "off") E
				
					S ":ایمیل" E
					S br() E
					S br() E			
					S input().set("type", "text").set("name", "email") E
					S br() E
					S br() E
	
					S ":پسورد" E
					S br() E
					S br() E
					S input().set("type", "text").set("name", "password") E
					S br() E
					S br() E
					
					S ":تایید پسورد" E
					S br() E
					S br() E
					S input().set("type", "text").set("name", "passwordConfirm") E
					S br() E
					S br() E
	
					//generate a random number and send the random number to server.
					srand(time(NULL));
					string genCaptcha = to_string(rand()%10 + 1);
					S input().set("type", "hidden").set("name", "genCaptcha").set("value", genCaptcha) E
					S br() E
				
					//load the address of webCaptcha from dataBase.
					SERVER = "tcp://127.0.0.1:3306";
					USER = "testing";
					PASSWORD = "testing";
					DATABASE = "captcha";

	
					driver = get_driver_instance();
					con = driver->connect(SERVER, USER, PASSWORD);
					stmt = con->createStatement();
					stmt->execute("USE " + DATABASE);
	
					pstmt = con->prepareStatement
					("SELECT imageDir FROM captchaImages WHERE id = ?");
					pstmt->setString(1, genCaptcha);
	
					string dirHolder = "http://strongwow.ir/";
					res = pstmt->executeQuery();
					while(res->next() == true)
						dirHolder += res->getString("imageDir");
					delete con;
					delete stmt;
					delete pstmt;
					delete res;
	
					//loading image of captcha
					S ":لطفا حرفی که در کپچا میبینید را در کادر بنویسید" E
					S br() E
					S br() E
					S img().set("src", dirHolder)
								 .set("width", "100").set("height", "80")
								 .set("onContextMenu", "return false")
								 .set("alt", "please report that captcha didn't load") E
	
					S br() E
					S br() E
					S input().set("type", "text").set("name", "userCaptcha") E
					S br() E
					S br() E
					S input().set("type", "submit").set("value", "submit") E
					
				S form() E
			S cgicc::div() E
			
			S a("بازگشت به صفحه اول").set("href", "http://strongwow.ir/") E
			
		S body() E		
S html() E
}













