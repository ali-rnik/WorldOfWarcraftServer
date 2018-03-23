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
			S title("SignUp Page") E
			S meta().set("charset", "UTF-8") E
			S meta().set("name", "viewport").set("content", "width=device-width, initial-scale=1.0") E
			S cgicc::link().set("rel", "icon").set("href", "http://strongwow.ir/media/tabicon.png") E
			S cgicc::link().set("rel", "stylesheet").set("href", "http://strongwow.ir/styles.css") E
		S head() E
		S body() E
		
			S p(".را دانلود کنید، حجم تقریبی بازی (18 گیگـ) میباشد 'World of Warcraft Wrath of the Lich King 3.3.5a' برای دانلود بازی به لینک زیر رفته و نسخه ") E
			S br() E
			S a("لینک دانلود بازی")
			.set("href", "https://download.ir/%D8%AF%D8%A7%D9%86%D9%84%D9%88%D8%AF-%D9%85%D8%AC%D9%85%D9%88%D8%B9%D9%87-%D8%A8%D8%A7%D8%B2%DB%8C-world-of-warcraft-%D8%A8%D8%B1%D8%A7%DB%8C-%DA%A9%D8%A7%D9%85%D9%BE%DB%8C%D9%88%D8%AA%D8%B1/")
			 .set("target", "_blank") E
			S br() E
			S br() E
			S p(".بگردید و وارد آن شوید enUS یا enGB شوید سپس دنبال پوشه data بعد از دانلود بازی و نصب آن به پوشه بازی رفته و وارد پوشه") E
			S br() E
			S p(".کنید save و کل محتویات آن را پاک کرده و عبارت زیر را در آن کپی کنید و سپس آن را notepad را با باز کنید realmlist.wtf حال پوشه") E
			S br() E
			S p("set realmlist 207.154.255.147") E
			S br() E
			S p(".که در پوشه بازی قرار دارد بازی را اجرا کنید و پس از وارد کردن اطلاعات اکانتی که ساخته اید وارد بازی شده و از بازی لذت ببرید wow.exe حالا میتوانید با باز کردن فایل") E
			S br() E
			
			S a("بازگشت به صفحه اول").set("href", "http://strongwow.ir/") E
			
		S body() E		
S html() E
}


