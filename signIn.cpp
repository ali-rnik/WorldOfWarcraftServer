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

int main()
{

S HTTPHTMLHeader() E

S html() E
		S head() E
			S title("SignIn Page") E
			S meta().set("name", "viewport").set("content", "width=device-width, initial-scale=1.0") E
			S meta().set("charset", "UTF-8") E
			S cgicc::link().set("rel", "icon").set("href", "http://strongwow.ir/media/tabicon.png") E
			S cgicc::link().set("rel", "stylesheet").set("href", "http://strongwow.ir/styles.css") E
		S head() E
		S body() E
			S h1(".این قسمت به زودی راه اندازی می شود. شما فعلا می توانید پس از ثبت نام وارد بازی شوید") E
			S br() E
			S a("بازگشت به صفحه اول").set("href", "http://strongwow.ir/") E
		S body() E		
S html() E
}


