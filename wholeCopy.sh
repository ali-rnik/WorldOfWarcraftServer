#!/bin/bash

sudo find . -name \*.cgi -exec cp {}  /usr/lib/cgi-bin/ \;
sudo cp styles.css index.html /var/www/html/
sudo cp -r captchaImages media /var/www/html/
sudo cp verifyEmail.sh /usr/lib/cgi-bin/ 
