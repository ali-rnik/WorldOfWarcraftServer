
create table captchaImages
(
	id int,
	imageDir varchar(255),
	imageText varchar(255),
	imageName varchar(255)
);

insert into captchaImages
(	id, imageDir,               imageText, imageName)
values
(	1, 'captchaImages/one.png'  , 'salam'      , 'one.png'   ),
(	2, 'captchaImages/two.png'  , 'breserker'  , 'two.png'   ),
(	3, 'captchaImages/three.png', 'ashes'      , 'three.png' ),
(	4, 'captchaImages/four.png' , 'running'    , 'four.png'  ),
(	5, 'captchaImages/five.png' , 'violin'     , 'five.png'  ),
(	6, 'captchaImages/six.png'  , 'wowisgood'  , 'six.png'   ),
(	7, 'captchaImages/seven.png', 'khoobi'     , 'seven.png' ),
(	8, 'captchaImages/eight.png', 'militwo'    , 'eight.png' ),
(	9, 'captchaImages/nine.png' , 'cleansi'    , 'nine.png'  ),
(	10, 'captchaImages/ten.png' , 'smshd'      , 'ten.png'   );


GRANT SELECT,INSERT,UPDATE,DELETE,CREATE,DROP,ALTER on captchaImages to 'testing'@'localhost' identified by 'testing';
