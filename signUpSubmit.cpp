//c, c++
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

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
S	html() E	
	S	head() E	
		S	title("SignUp page") E
		S meta().set("charset", "UTF-8") E
	S	head() E	
	S body() E	
		
		//fetching data from form.
		Cgicc fetchFrom;
		string email           = fetchFrom("email");
		string password 			 = fetchFrom("password");
		string passwordConfirm = fetchFrom("passwordConfirm");
		string userCaptcha     = fetchFrom("userCaptcha");
		string genCaptcha      = fetchFrom("genCaptcha");
		
		//define variables;
		string gmail = "", isExist = "", userName = "";
		
		/*debug
		
		email = "strongi@gmail.com";
		password = "4aliali";
		passwordConfirm = "4aliali";
		userCaptcha = "breserker";
		genCaptcha = "2";
		*/
		
		//checking genCaptcha ?= userCaptcha
    SERVER = "tcp://127.0.0.1:3306";
    USER = "testing";
	 	PASSWORD = "testing";
	  DATABASE = "captcha";
	 	
		driver = get_driver_instance();
		con = driver->connect(SERVER, USER, PASSWORD);
		stmt = con->createStatement();
		stmt->execute("USE " + DATABASE);

		pstmt = con->prepareStatement
		("SELECT imageText FROM captchaImages WHERE id = ?");
		pstmt->setString(1, genCaptcha);

		res = pstmt->executeQuery();
		while(res->next() == true)
			genCaptcha = res->getString("imageText");
		
		delete con;
		delete stmt;
		delete pstmt;
		delete res;
		
		//checking captcha.
		if(genCaptcha != userCaptcha)
		{
			S p("!شاید حروف کپچا را اشتباه وارد کرده اید") E
			S a("بازگشت به صفحه اول").set("href", "main.cgi") E
			goto labelH;
		}
		
		//checking email length.
		if(email.size() > 32 || email.size() < 13)
		{
			S p(".ایمیل شما اشتباه وارد شده است") E
			S p("!ایمیل باید نهایتا 32 کاراکتر باشد و حداقل 13 کاراکتر") E
			S a("بازگشت به صفحه اول").set("href", "main.cgi") E
			goto labelH;
		}
		
		//checking email spaces.
		for(int i = 0; i < (int)email.size(); i++)
		{
			if(email[i] == ' ')
			{
				S p(".ایمیل شما اشتباه وارد شده است") E
				S p(".ایمیل شما دارای فضای خالی (اسپیس) است") E
				S a("بازگشت به صفحه اول").set("href", "main.cgi") E
				goto labelH;
			}
		}
		//checking email contain gmail	
		for(int i = email.size()-10; i < (int)email.size(); i++)
			gmail += email[i];
		if(gmail != "@gmail.com")
		{
			S p(".ایمیل شما اشتباه وارد شده است") E
			S p(".ایمیل شما باید حتما جی میل باشد") E
			S a("بازگشت به صفحه اول").set("href", "main.cgi") E
			goto labelH;
		}
		
		//checking not exist in dataBase
		SERVER = "tcp://127.0.0.1:3306";
    USER = "Trinity";
	 	PASSWORD = "Trinity";
	  DATABASE = "auth";
	 	
		driver = get_driver_instance();
		con = driver->connect(SERVER, USER, PASSWORD);
		stmt = con->createStatement();
		stmt->execute("USE " + DATABASE);
				
		pstmt = con->prepareStatement
    ("SELECT username FROM account WHERE username = ?");
		pstmt->setString(1, email);
		res = pstmt->executeQuery();
		while(res->next() == true)
			isExist = res->getString("username");
		if(isExist != "")
		{
			S p(".بنظر می رسد با ایمیل شما اکانتی موجود است") E
			S a("بازگشت به صفحه اول").set("href", "main.cgi") E
			goto labelH;
		}

		delete con;
		delete stmt;
		delete pstmt;
		delete res;
		
		//checking password length
		if(password.size() > 30 || password.size() < 6)
		{
			S p(".پسورد شما اشتباه وارد شده است") E
			S p("!پسورد باید نهایتا 30 کاراکتر باشد و حداقل 6 کاراکتر") E
			S a("بازگشت به صفحه اول").set("href", "main.cgi") E
			goto labelH;
		}
	
		//checking password format;
		for(int i = 0; i < (int)password.size(); i++)
		{
			if(isdigit(password[i]) == false && isalpha(password[i]) == false)
			{
				S p(".پسورد شما اشتباه وارد شده است") E
				S p(".پسورد شما فقط باید دارای حروف و اعداد انگلیسی باشد") E
				S a("بازگشت به صفحه اول").set("href", "main.cgi") E
				goto labelH;
			}
		}
		
		//checking wether email is real
		
		
		//------------------------------correctness confirmed-----------------//
		
		
		//creating username based on email;
		for(int i = email.size()-11; i >= 0; i--)
			userName+=email[i];
		reverse(userName.begin(), userName.end());
		
		
		//creating account
		SERVER = "tcp://127.0.0.1:3306";
    USER = "Trinity";
	 	PASSWORD = "Trinity";
	  DATABASE = "auth";
	 	
		driver = get_driver_instance();
		con = driver->connect(SERVER, USER, PASSWORD);
		
		stmt = con->createStatement();

		
		stmt->execute("USE " + DATABASE);
		
		stmt->executeQuery("select @username");
		pstmt = con->prepareStatement("set @username = ?");
		pstmt->setString(1, userName);
		pstmt->execute();
		delete pstmt;
		
		stmt->executeQuery("select @password");
		pstmt = con->prepareStatement("set @password = ?");
		pstmt->setString(1, password);
		pstmt->execute();
		delete pstmt;
				
		stmt->executeQuery("select @hash");
		stmt->execute("set @hash = SHA1(CONCAT(UPPER(@username), ':', UPPER(@password)))");
		
		stmt->execute("insert into account (username, sha_pass_hash) values (@username, @hash)");
		
		delete con;
		delete stmt;
		
		S p("Account created successfuly with the following information : ") E
		S p("Your Battle.net Account Name: " + userName) E
		S p("Your Password: " + password) E
		S a("بازگشت به صفحه اول").set("href", "main.cgi") E
	labelH : 
	S body() E	
S html() E
return 0;	
}
