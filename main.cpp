#include <iostream>
#include <string>
#include <stdio.h>

#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>

using namespace std;
using namespace cgicc;

#define S	 cout << 
#define E  << endl;

int main()
{
S HTTPHTMLHeader() E	
S	html() E	
	S	head() E	
		S	title("main page wow") E	
	S	head() E	
	S body() E	
		S	p("welcome to my wow server") E	
		S	a("please click here to signUp").set("href","signUp.cgi") E	
		S	br() E	
		S a("please click here to signIn").set("href","sigIn.cgi") E
	S body() E	
S html() E	
}
