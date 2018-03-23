#!/bin/bash

compile_and_link ()
{
	g++ -std=c++11 -g -Wall -I/usr/include/cppconn -o $2 $1 -L/usr/lib -lmysqlcppconn -lcgicc
}

if compile_and_link signUp.cpp signUp.cgi; then
	echo "signUp compiled"
else
	echo "signUp error detected"
fi

	
if compile_and_link signUpSubmit.cpp signUpSubmit.cgi; then
	echo "signUpSubmit compiled"
else
	echo "signUpSubmit error detected"
fi

if compile_and_link info.cpp info.cgi; then
	echo "info compiled"
else
	echo "info error detected"
fi

if compile_and_link signIn.cpp signIn.cgi; then
	echo "signIn compiled"
else
	echo "signIn error detected"
fi

if compile_and_link verifySignUp.cpp verifySignUp.cgi; then
	echo "verifySignUp compiled"
else
	echo "verifySignUp error detected"
fi

