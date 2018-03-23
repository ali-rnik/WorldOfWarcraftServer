#!/bin/bash
echo -e \
                  " درود به شما،\n\n  این ایمیل برای تایید ساخت اکانت شما از طرف  Strongwow.ir فرستاده شده است. \n\n  برای تایید اکانت خود از کد زیر استفاده کنید : $1"\
| mail -a "From: Strongwow.ir <Strongwow@strongwow.ir>" \
       -a "Subject: تایید اکانت Strongwow" \
       -a "X-Custom-Header: yes" $2  
       
       
       
       
       
       

       
