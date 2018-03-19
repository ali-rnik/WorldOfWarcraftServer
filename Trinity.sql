create database auth;

use auth;

create table account
(
	id int,
	username varchar(255),
	sha_pass_hash varchar(255)
);

GRANT SELECT,INSERT,UPDATE,DELETE,CREATE,DROP,ALTER on account to 'user'@'localhost' identified by 'pass';



select @username;
set @username = 'strongsaxophone@gmail.com';

select @password;
set @password = 'strongsaxophone';

select @hash;
set @hash = SHA1(CONCAT(UPPER(@username), ':', UPPER(@password)));

insert into account
(username, sha_pass_hash)
values
(@username, @hash); 
