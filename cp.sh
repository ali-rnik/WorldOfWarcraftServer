#!/bin/bash
g++ -std=c++11 -g -Wall -I/usr/include/cppconn -o $4 $3 $2 $1 -L/usr/lib -lmysqlcppconn -lcgicc

