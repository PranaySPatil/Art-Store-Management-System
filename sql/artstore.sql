

INSERT INTO artstoremgmtsys2.painting (pid, name, medium, subject, area, id, sold_by, sold_to, url, century, date, price) VALUES (1, 'Rose', 'oil', 'potrait', 10000, 1, 'prathmesh', 'jeet', 'rose.jpeg', 20, '2015-12-28', 12000);
INSERT INTO artstoremgmtsys2.painting (pid, name, medium, subject, area, id, sold_by, sold_to, url, century, date, price) VALUES (2, 'Lily', 'oil', 'potrait', 10020, 2, 'pranay', 'pranay', 'lily.jpeg', 19, '2015-09-18', 13000);
INSERT INTO artstoremgmtsys2.painting (pid, name, medium, subject, area, id, sold_by, sold_to, url, century, date, price) VALUES (3, 'Sunflower', 'oil', 'potrait', 13000, 3, 'jeet', 'prathmesh', 'sunflower.jpeg', 19, '2015-11-19', 15890);
INSERT INTO artstoremgmtsys2.painting (pid, name, medium, subject, area, id, sold_by, sold_to, url, century, date, price) VALUES (4, 'Bike', 'water', 'still-life', 9000, 1, 'pranay', 'jeet', 'bike.jpeg', 20, '2015-08-12', 29000);
INSERT INTO artstoremgmtsys2.painting (pid, name, medium, subject, area, id, sold_by, sold_to, url, century, date, price) VALUES (5, 'Car', 'water', 'still-life', 12450, 2, 'prathmesh', 'pranay', 'car.jpeg', 20, '2015-07-26', 13980);
INSERT INTO artstoremgmtsys2.painting (pid, name, medium, subject, area, id, sold_by, sold_to, url, century, date, price) VALUES (6, 'Aeroplane', 'water', 'still-life', 11230, 3, 'pranay', 'prathmesh', 'aeroplane.jpeg', 20, '2015-02-13', 14500);
INSERT INTO artstoremgmtsys2.painting (pid, name, medium, subject, area, id, sold_by, sold_to, url, century, date, price) VALUES (7, 'Village Life', 'color', 'landscape', 20006, 1, 'jeet', 'jeet', 'village_life.jpeg', 19, '2016-01-12', 24890);
INSERT INTO artstoremgmtsys2.painting (pid, name, medium, subject, area, id, sold_by, sold_to, url, century, date, price) VALUES (8, 'City Life', 'color', 'landscape', 12900, 2, 'prathmesh', 'pranay', 'city_life.jpeg', 19, '2016-02-19', 31689);
INSERT INTO artstoremgmtsys2.painting (pid, name, medium, subject, area, id, sold_by, sold_to, url, century, date, price) VALUES (9, 'Empty Room', 'color', 'landscape', 23001, 3, 'jeet', 'prathmesh', 'empty_room.jpeg', 19, '2016-03-11', 21345);
INSERT INTO artstoremgmtsys2.painting (pid, name, medium, subject, area, id, sold_by, sold_to, url, century, date, price) VALUES (10, 'Child Playing', 'color', 'landscape', 9800, 1, 'prathmesh', 'jeet', 'child_playing.jpeg', 18, '2015-07-13', 29000);
INSERT INTO artstoremgmtsys2.painting (pid, name, medium, subject, area, id, sold_by, sold_to, url, century, date, price) VALUES (11, 'Fire Crackers', 'oil', 'potrait', 12000, 1, 'jeet', 'prathmesh', 'fire_crackers.jpeg', 20, '2016-02-19', 22000);
INSERT INTO artstoremgmtsys2.painting (pid, name, medium, subject, area, id, sold_by, sold_to, url, century, date, price) VALUES (12, 'Football Match', 'color', 'landscape', 15000, 2, 'jeet', 'pranay', 'football.jpeg', 20, '2016-01-28', 12890);
INSERT INTO artstoremgmtsys2.painting (pid, name, medium, subject, area, id, sold_by, sold_to, url, century, date, price) VALUES (13, 'Independence Day', 'water', 'landscape', 25000, 3, 'pranay', 'prathmesh', 'independence_day.jpeg', 19, '2015-08-16', 14234);
INSERT INTO artstoremgmtsys2.painting (pid, name, medium, subject, area, id, sold_by, sold_to, url, century, date, price) VALUES (14, 'Sachin Tendulakar', 'oil', 'potrait', 9000, 1, 'pranay', 'jeet', 'sachin.jpeg', 20, '2015-09-21', 16538);
INSERT INTO artstoremgmtsys2.painting (pid, name, medium, subject, area, id, sold_by, sold_to, url, century, date, price) VALUES (15, 'Holi', 'water', 'landscape', 14500, 2, 'prathmesh', 'jeet', 'holi.jpeg', 19, '2015-04-27', 14632);
INSERT INTO artstoremgmtsys2.painting (pid, name, medium, subject, area, id, sold_by, sold_to, url, century, date, price) VALUES (16, 'Abstract Art', 'water', 'still-life', 12890, 3, 'prathmesh', 'pranay', 'abstarct.jpeg', 18, '2015-08-23', 22000);



CREATE TABLE artstoremgmtsys2.available
(pid INT NOT NULL,
price INT NOT NULL,
PRIMARY KEY (pid),
Foreign KEY pid1(pid)
References painting(pid)
);

CREATE TABLE artstoremgmtsys2.jeet_available
(pid INT NOT NULL,
sell TINYINT(1),
PRIMARY KEY (pid),
Foreign KEY pid1(pid)
References painting(pid)
);

CREATE TABLE artstoremgmtsys2.pranay_available
(pid INT NOT NULL,
sell TINYINT(1),
PRIMARY KEY (pid),
Foreign KEY pid1(pid)
References painting(pid)
);

CREATE TABLE artstoremgmtsys2.prathmesh_available
(pid INT NOT NULL,
sell TINYINT(1),
PRIMARY KEY (pid),
Foreign KEY pid1(pid)
References painting(pid)
);

CREATE TABLE artstoremgmtsys2.jeet_purchased
(pid INT NOT NULL,
date DATE NOT NULL,
p_price Int(25) NOT NULL,
opt_price Int(25) ,
PRIMARY KEY (pid),
Foreign KEY pid1(pid)
References painting(pid)
);

CREATE TABLE artstoremgmtsys2.pranay_purchased
(pid INT NOT NULL,
date DATE NOT NULL,
p_price Int(25) NOT NULL,
opt_price Int(25) ,
PRIMARY KEY (pid),
Foreign KEY pid1(pid)
References painting(pid)
);

CREATE TABLE artstoremgmtsys2.prathmesh_purchased
(pid INT NOT NULL,
date DATE NOT NULL,
p_price Int(25) NOT NULL,
opt_price Int(25) ,
PRIMARY KEY (pid),
Foreign KEY pid1(pid)
References painting(pid)
);

CREATE TABLE artstoremgmtsys2.pranay_sold
(pid INT NOT NULL,
date DATE NOT NULL,
s_price Int NOT NULL,
opt_price Int ,
PRIMARY KEY (pid),
Foreign KEY pid1(pid)
References painting(pid)
);

CREATE TABLE artstoremgmtsys2.prathmesh_sold
(pid INT NOT NULL,
date DATE NOT NULL,
s_price Int NOT NULL,
opt_price Int ,
PRIMARY KEY (pid),
Foreign KEY pid1(pid)
References painting(pid)
);

CREATE TABLE artstoremgmtsys2.jeet_sold
(pid INT NOT NULL,
date DATE NOT NULL,
s_price Int NOT NULL,
opt_price Int ,
PRIMARY KEY (pid),
Foreign KEY pid1(pid)
References painting(pid)
);

delete from jeet_purchased;
delete from pranay_purchased;
delete from prathmesh_purchased;

delete from jeet_sold;
delete from pranay_sold;
delete from prathmesh_sold;

delete from jeet_available;
delete from pranay_available;
delete from prathmesh_AVAILABLE;

insert into artstoremgmtsys2.jeet_purchased(pid,date,p_price)
select pid,date,price from artstoremgmtsys2.painting where sold_to = "jeet";

insert into artstoremgmtsys2.pranay_purchased(pid,date,p_price)
select pid,date,price from artstoremgmtsys2.painting where sold_to = "pranay";

insert into artstoremgmtsys2.prathmesh_purchased(pid,date,p_price)
select pid,date,price from artstoremgmtsys2.painting where sold_to = "prathmesh";

insert into artstoremgmtsys2.jeet_sold(pid,date,s_price)
select pid,date,price from artstoremgmtsys2.painting where sold_by = "jeet";

insert into artstoremgmtsys2.pranay_sold(pid,date,s_price)
select pid,date,price from artstoremgmtsys2.painting where sold_by = "pranay";

insert into artstoremgmtsys2.prathmesh_sold(pid,date,s_price)
select pid,date,price from artstoremgmtsys2.painting where sold_by = "prathmesh";

insert into artstoremgmtsys2.jeet_available(pid)
select pid from artstoremgmtsys2.jeet_purchased;
update artstoremgmtsys2.jeet_available
set sell = 0;

insert into artstoremgmtsys2.pranay_available(pid)
select pid from artstoremgmtsys2.pranay_purchased;
update artstoremgmtsys2.pranay_available
set sell = 0;

insert into artstoremgmtsys2.prathmesh_available(pid)
select pid from artstoremgmtsys2.prathmesh_purchased;
update artstoremgmtsys2.prathmesh_available
set sell = 0;



UPDATE artstoremgmtsys2.JEET_available SET sell = 1 WHERE pid = 1;
UPDATE artstoremgmtsys2.JEET_available SET sell = 1 WHERE pid = 4;
UPDATE artstoremgmtsys2.JEET_available SET sell = 1 WHERE pid = 7;

INSERT INTO artstoremgmtsys2.AVAILABLE (pid, price) VALUES (1, 13000);
INSERT INTO artstoremgmtsys2.AVAILABLE (pid, price) VALUES (4, 31000);
INSERT INTO artstoremgmtsys2.AVAILABLE (pid, price) VALUES (7, 24000);

UPDATE artstoremgmtsys2.pranay_available SET sell = 1 WHERE pid = 2;
UPDATE artstoremgmtsys2.pranay_available SET sell = 1 WHERE pid = 5;
UPDATE artstoremgmtsys2.pranay_available SET sell = 1 WHERE pid = 8;

INSERT INTO artstoremgmtsys2.AVAILABLE (pid, price) VALUES (2, 13980);
INSERT INTO artstoremgmtsys2.AVAILABLE (pid, price) VALUES (5, 15000);
INSERT INTO artstoremgmtsys2.AVAILABLE (pid, price) VALUES (8, 33000);

UPDATE artstoremgmtsys2.prathmesh_available SET sell = 1 WHERE pid = 3;
UPDATE artstoremgmtsys2.prathmesh_available SET sell = 1 WHERE pid = 6;
UPDATE artstoremgmtsys2.prathmesh_available SET sell = 1 WHERE pid = 11;

INSERT INTO artstoremgmtsys2.AVAILABLE (pid, price) VALUES (3, 14890);
INSERT INTO artstoremgmtsys2.AVAILABLE (pid, price) VALUES (6, 16000);
INSERT INTO artstoremgmtsys2.AVAILABLE (pid, price) VALUES (11, 23000);

UPDATE artstoremgmtsys2.jeet_purchased SET opt_price = 12500 WHERE pid = 1;
UPDATE artstoremgmtsys2.jeet_purchased SET opt_price = 27800 WHERE pid = 4;
UPDATE artstoremgmtsys2.jeet_purchased SET opt_price = 23000 WHERE pid = 7;
UPDATE artstoremgmtsys2.jeet_purchased SET opt_price = 29000 WHERE pid = 10;
UPDATE artstoremgmtsys2.jeet_purchased SET opt_price = 15890 WHERE pid = 14;
UPDATE artstoremgmtsys2.jeet_purchased SET opt_price = 12000 WHERE pid = 15;

UPDATE artstoremgmtsys2.pranay_purchased SET opt_price = 12000 WHERE pid = 2;
UPDATE artstoremgmtsys2.pranay_purchased SET opt_price = 14000 WHERE pid = 5;
UPDATE artstoremgmtsys2.pranay_purchased SET opt_price = 30000 WHERE pid = 8;
UPDATE artstoremgmtsys2.pranay_purchased SET opt_price = 10000 WHERE pid = 12;
UPDATE artstoremgmtsys2.pranay_purchased SET opt_price = 21000 WHERE pid = 16;

UPDATE artstoremgmtsys2.prathmesh_purchased SET opt_price = 14000 WHERE pid = 3;
UPDATE artstoremgmtsys2.prathmesh_purchased SET opt_price = 14890 WHERE pid = 6;
UPDATE artstoremgmtsys2.prathmesh_purchased SET opt_price = 20000 WHERE pid = 9;
UPDATE artstoremgmtsys2.prathmesh_purchased SET opt_price = 21112 WHERE pid = 11;
UPDATE artstoremgmtsys2.prathmesh_purchased SET opt_price = 14500 WHERE pid = 13;

UPDATE artstoremgmtsys2.jeet_sold SET opt_price = 14000 WHERE pid = 3;
UPDATE artstoremgmtsys2.jeet_sold SET opt_price = 23000 WHERE pid = 7;
UPDATE artstoremgmtsys2.jeet_sold SET opt_price = 20000 WHERE pid = 9;
UPDATE artstoremgmtsys2.jeet_sold SET opt_price = 21112 WHERE pid = 11;
UPDATE artstoremgmtsys2.jeet_sold SET opt_price = 10000 WHERE pid = 12;


UPDATE artstoremgmtsys2.pranay_sold SET opt_price = 12000 WHERE pid = 2;
UPDATE artstoremgmtsys2.pranay_sold SET opt_price = 27800 WHERE pid = 4;
UPDATE artstoremgmtsys2.pranay_sold SET opt_price = 14890 WHERE pid = 6;
UPDATE artstoremgmtsys2.pranay_sold SET opt_price = 27800 WHERE pid = 13;
UPDATE artstoremgmtsys2.pranay_sold SET opt_price = 15890 WHERE pid = 14;


UPDATE artstoremgmtsys2.prathmesh_sold SET opt_price = 12500 WHERE pid = 1;
UPDATE artstoremgmtsys2.prathmesh_sold SET opt_price = 14000 WHERE pid = 5;
UPDATE artstoremgmtsys2.prathmesh_sold SET opt_price = 30000 WHERE pid = 8;
UPDATE artstoremgmtsys2.prathmesh_sold SET opt_price = 29000 WHERE pid = 10;
UPDATE artstoremgmtsys2.prathmesh_sold SET opt_price = 12000 WHERE pid = 15;
UPDATE artstoremgmtsys2.prathmesh_sold SET opt_price = 21000 WHERE pid = 16;

