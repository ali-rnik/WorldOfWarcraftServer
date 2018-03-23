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
		S meta().set("name", "viewport").set("content", "width=device-width, initial-scale=1.0") E
		S cgicc::link().set("rel", "icon").set("href", "http://strongwow.ir/media/tabicon.png") E
		S cgicc::link().set("rel", "stylesheet").set("href", "http://strongwow.ir/styles.css") E
	S	head() E	
	S body() E
	
 		//fetching data from form.
		Cgicc fetchFrom;
		string realUserName    = fetchFrom("userName");
		string unValidVer 		 = fetchFrom("unvalidVer");
		
		//creating fake username
		string fakeUserName = realUserName+"un", validVer = "";
		
		//fetching validVer from database to compare by unvalidVer;
		SERVER = "tcp://127.0.0.1:3306";
    USER = "Trinity";
	 	PASSWORD = "Trinity";
	  DATABASE = "auth";
	  
	  driver = get_driver_instance();
		con = driver->connect(SERVER, USER, PASSWORD);
		stmt = con->createStatement();
		stmt->execute("USE " + DATABASE);
		
		pstmt = con->prepareStatement
    ("SELECT validVer FROM account WHERE username = ?");
		pstmt->setString(1, fakeUserName);
		res = pstmt->executeQuery();
		while(res->next() == true)
			validVer = res->getString("validVer");
		delete res;
		delete pstmt;
		
		// comparing validVer and unvalidVer
		
		//creating account
		if(validVer == unValidVer)
		{
			//update realUserName Instead of fakeUserName
			pstmt = con->prepareStatement
    	("update account set username = ? where username = ?");
    	pstmt->setString(1, realUserName);
			pstmt->setString(2, fakeUserName);
			pstmt->execute();
			delete pstmt;
			S br() E
			S br() E
			S p(".اکانت شما با موفقیت ساخته شد") E
			S br() E
			S a("بازگشت به صفحه اول").set("href", "http://strongwow.ir/") E
		}
		//removing info from database
		else
		{
			//delete fakeuserName from database
			pstmt = con->prepareStatement
    	("delete  from account where username = ?");
    	pstmt->setString(1, fakeUserName);
			pstmt->execute();
			delete pstmt;
			S br() E
			S br() E
			S p(".کد تایید را اشتباه وارد کردید.از دوباره اکانت بسازید") E
			S br() E
			S a("بازگشت به صفحه اول").set("href", "http://strongwow.ir/") E
		}			
						
	S body() E	
S html() E
return 0;	
}
