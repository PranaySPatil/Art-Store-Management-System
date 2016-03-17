create database artstoremgmt;
use artstoremgmt;


CREATE TABLE artstoremgmt.login
(username VARCHAR(10) NOT NULL,
password VARCHAR(25) NOT NULL,
PRIMARY KEY (username));

INSERT INTO artstoremgmt.login (username, password) VALUES ('jeet', 'qwertyui');
INSERT INTO artstoremgmt.login (username, password) VALUES ('prathmesh', 'qwertyui');
INSERT INTO artstoremgmt.login (username, password) VALUES ('pranay', 'qwertyui');


CREATE TABLE artstoremgmt.artist
(id INT NOT NULL,
name VARCHAR(15) NOT NULL,
fa Double DEFAULT 1.0,
PRIMARY KEY (id));

INSERT INTO artstoremgmt.artist (id, name, fa) VALUES (1, 'Kiran ', 1.2);
INSERT INTO artstoremgmt.artist (id, name, fa) VALUES (2, 'Raj', 1.4);
INSERT INTO artstoremgmt.artist (id, name, fa) VALUES (3, 'Mohan', 1.1);


CREATE TABLE artstoremgmt.painting
(pid INT NOT NULL,
name VARCHAR(25) NOT NULL,
medium VARCHAR(25) NOT NULL CHECK (medium IN ('oil','water','color')),
subject VARCHAR(25) NOT NULL CHECK (subject IN ('still-life','landscape','potrait')),
area INT NOT NULL,
id INT NOT NULL,
sold_by VARCHAR(10),
sold_to VARCHAR(10),
url VARCHAR(100) NOT NULL,
century INT NOT NULL,
date DATE,
FOREIGN KEY fk_user(id)
REFERENCES artist(id),
price INT,
PRIMARY KEY (pid));

INSERT INTO artstoremgmt.painting (pid, name, medium, subject, area, id, sold_by, sold_to, url, century, date, price) VALUES (1, 'Rose', 'oil', 'potrait', 10000, 1, 'prathmesh', 'jeet', 'rose.jpeg', 20, '2015-12-28', 12000);
INSERT INTO artstoremgmt.painting (pid, name, medium, subject, area, id, sold_by, sold_to, url, century, date, price) VALUES (2, 'Lily', 'oil', 'potrait', 10020, 2, 'pranay', 'pranay', 'lily.jpeg', 19, '2015-09-18', 13000);
INSERT INTO artstoremgmt.painting (pid, name, medium, subject, area, id, sold_by, sold_to, url, century, date, price) VALUES (3, 'Sunflower', 'oil', 'potrait', 13000, 3, 'jeet', 'prathmesh', 'sunflower.jpeg', 19, '2015-11-19', 15890);
INSERT INTO artstoremgmt.painting (pid, name, medium, subject, area, id, sold_by, sold_to, url, century, date, price) VALUES (4, 'Bike', 'water', 'still-life', 9000, 1, 'pranay', 'jeet', 'bike.jpeg', 20, '2015-08-12', 29000);
INSERT INTO artstoremgmt.painting (pid, name, medium, subject, area, id, sold_by, sold_to, url, century, date, price) VALUES (5, 'Car', 'water', 'still-life', 12450, 2, 'prathmesh', 'pranay', 'car.jpeg', 20, '2015-07-26', 13980);
INSERT INTO artstoremgmt.painting (pid, name, medium, subject, area, id, sold_by, sold_to, url, century, date, price) VALUES (6, 'Aeroplane', 'water', 'still-life', 11230, 3, 'pranay', 'prathmesh', 'aeroplane.jpeg', 20, '2015-02-13', 14500);
INSERT INTO artstoremgmt.painting (pid, name, medium, subject, area, id, sold_by, sold_to, url, century, date, price) VALUES (7, 'Village Life', 'color', 'landscape', 20006, 1, 'jeet', 'jeet', 'village_life.jpeg', 19, '2016-01-12', 24890);
INSERT INTO artstoremgmt.painting (pid, name, medium, subject, area, id, sold_by, sold_to, url, century, date, price) VALUES (8, 'City Life', 'color', 'landscape', 12900, 2, 'prathmesh', 'pranay', 'city_life.jpeg', 19, '2016-02-19', 31689);
INSERT INTO artstoremgmt.painting (pid, name, medium, subject, area, id, sold_by, sold_to, url, century, date, price) VALUES (9, 'Empty Room', 'color', 'landscape', 23001, 3, 'jeet', 'prathmesh', 'empty_room.jpeg', 19, '2016-03-11', 21345);
INSERT INTO artstoremgmt.painting (pid, name, medium, subject, area, id, sold_by, sold_to, url, century, date, price) VALUES (10, 'Child Playing', 'color', 'landscape', 9800, 1, 'prathmesh', 'jeet', 'child_playing.jpeg', 18, '2015-07-13', 29000);



CREATE TABLE artstoremgmt.available
(pid INT NOT NULL,
price INT NOT NULL,
PRIMARY KEY (pid),
Foreign KEY pid1(pid)
References painting(pid)
);

CREATE TABLE artstoremgmt.jeet_available
(pid INT NOT NULL,
sell TINYINT(1),
PRIMARY KEY (pid),
Foreign KEY pid1(pid)
References painting(pid)
);

CREATE TABLE artstoremgmt.pranay_available
(pid INT NOT NULL,
sell TINYINT(1),
PRIMARY KEY (pid),
Foreign KEY pid1(pid)
References painting(pid)
);

CREATE TABLE artstoremgmt.prathmesh_available
(pid INT NOT NULL,
sell TINYINT(1),
PRIMARY KEY (pid),
Foreign KEY pid1(pid)
References painting(pid)
);

CREATE TABLE artstoremgmt.jeet_purchased
(pid INT NOT NULL,
date DATE NOT NULL,
p_price Int(25) NOT NULL,
opt_price Int(25) ,
PRIMARY KEY (pid),
Foreign KEY pid1(pid)
References painting(pid)
);

CREATE TABLE artstoremgmt.pranay_purchased
(pid INT NOT NULL,
date DATE NOT NULL,
p_price Int(25) NOT NULL,
opt_price Int(25) ,
PRIMARY KEY (pid),
Foreign KEY pid1(pid)
References painting(pid)
);

CREATE TABLE artstoremgmt.prathmesh_purchased
(pid INT NOT NULL,
date DATE NOT NULL,
p_price Int(25) NOT NULL,
opt_price Int(25) ,
PRIMARY KEY (pid),
Foreign KEY pid1(pid)
References painting(pid)
);

CREATE TABLE artstoremgmt.pranay_sold
(pid INT NOT NULL,
date DATE NOT NULL,
s_price Int NOT NULL,
opt_price Int ,
PRIMARY KEY (pid),
Foreign KEY pid1(pid)
References painting(pid)
);

CREATE TABLE artstoremgmt.prathmesh_sold
(pid INT NOT NULL,
date DATE NOT NULL,
s_price Int NOT NULL,
opt_price Int ,
PRIMARY KEY (pid),
Foreign KEY pid1(pid)
References painting(pid)
);

CREATE TABLE artstoremgmt.jeet_sold
(pid INT NOT NULL,
date DATE NOT NULL,
s_price Int NOT NULL,
opt_price Int ,
PRIMARY KEY (pid),
Foreign KEY pid1(pid)
References painting(pid)
);

insert into artstoremgmt.jeet_purchased(pid,date,p_price)
select pid,date,price from artstoremgmt.painting where sold_to = "jeet";

insert into artstoremgmt.pranay_purchased(pid,date,p_price)
select pid,date,price from artstoremgmt.painting where sold_to = "pranay";

insert into artstoremgmt.prathmesh_purchased(pid,date,p_price)
select pid,date,price from artstoremgmt.painting where sold_to = "prathmesh";

insert into artstoremgmt.jeet_sold(pid,date,s_price)
select pid,date,price from artstoremgmt.painting where sold_by = "jeet";

insert into artstoremgmt.pranay_sold(pid,date,s_price)
select pid,date,price from artstoremgmt.painting where sold_by = "pranay";

insert into artstoremgmt.prathmesh_sold(pid,date,s_price)
select pid,date,price from artstoremgmt.painting where sold_by = "prathmesh";

insert into artstoremgmt.jeet_available(pid)
select pid from artstoremgmt.jeet_purchased;
update artstoremgmt.jeet_available
set sell = 0;

insert into artstoremgmt.pranay_available(pid)
select pid from artstoremgmt.pranay_purchased;
update artstoremgmt.pranay_available
set sell = 0;

insert into artstoremgmt.prathmesh_available(pid)
select pid from artstoremgmt.prathmesh_purchased;
update artstoremgmt.prathmesh_available
set sell = 0;

INSERT INTO artstoremgmt.AVAILABLE (pid, price) VALUES (1, 13000);
INSERT INTO artstoremgmt.AVAILABLE (pid, price) VALUES (8, 34000);
INSERT INTO artstoremgmt.AVAILABLE (pid, price) VALUES (9, 24000);

UPDATE artstoremgmt.jeet_available SET sell = 1 WHERE pid = 1;
UPDATE artstoremgmt.pranay_available SET sell = 1 WHERE pid = 8;
UPDATE artstoremgmt.prathmesh_available SET sell = 1 WHERE pid = 9;

