-- phpMyAdmin SQL Dump
-- version 4.5.5.1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Mar 21, 2016 at 06:38 AM
-- Server version: 5.7.9-log
-- PHP Version: 7.0.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `artstore`
--

-- --------------------------------------------------------

--
-- Table structure for table `artist`
--

CREATE TABLE `artist` (
  `id` int(11) NOT NULL,
  `name` varchar(15) NOT NULL,
  `fa` double DEFAULT '1'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `artist`
--

INSERT INTO `artist` (`id`, `name`, `fa`) VALUES
(1, 'Kiran ', 1.2),
(2, 'Raj', 1.4),
(3, 'Mohan', 1.1);

-- --------------------------------------------------------

--
-- Table structure for table `available`
--

CREATE TABLE `available` (
  `pid` int(11) NOT NULL,
  `price` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `available`
--

INSERT INTO `available` (`pid`, `price`) VALUES
(2, 13980),
(3, 14890),
(4, 31000),
(5, 15000),
(6, 16000),
(8, 33000);

-- --------------------------------------------------------

--
-- Table structure for table `jeet_available`
--

CREATE TABLE `jeet_available` (
  `pid` int(11) NOT NULL,
  `sell` tinyint(1) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `jeet_available`
--

INSERT INTO `jeet_available` (`pid`, `sell`) VALUES
(1, 0),
(4, 1),
(10, 0),
(14, 0),
(15, 0);

-- --------------------------------------------------------

--
-- Table structure for table `jeet_purchased`
--

CREATE TABLE `jeet_purchased` (
  `no` int(11) NOT NULL,
  `pid` int(11) NOT NULL,
  `date` date NOT NULL,
  `p_price` int(25) NOT NULL,
  `opt_price` int(25) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `jeet_purchased`
--

INSERT INTO `jeet_purchased` (`no`, `pid`, `date`, `p_price`, `opt_price`) VALUES
(1, 1, '2015-12-28', 12000, 12500),
(2, 4, '2015-08-12', 29000, 27800),
(3, 7, '2016-01-12', 24890, 23000),
(4, 10, '2015-07-13', 29000, 29000),
(5, 14, '2015-09-21', 16538, 15890),
(6, 15, '2015-04-27', 14632, 12000),
(7, 16, '2016-03-20', 15000, 22916);

-- --------------------------------------------------------

--
-- Table structure for table `jeet_sold`
--

CREATE TABLE `jeet_sold` (
  `no` int(11) NOT NULL,
  `pid` int(11) NOT NULL,
  `date` date NOT NULL,
  `s_price` int(11) NOT NULL,
  `opt_price` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `jeet_sold`
--

INSERT INTO `jeet_sold` (`no`, `pid`, `date`, `s_price`, `opt_price`) VALUES
(1, 1, '2016-03-20', 13000, 12164),
(2, 3, '2015-11-19', 15890, 14000),
(3, 7, '2016-01-12', 24890, 23000),
(4, 7, '2016-03-21', 24000, 37846),
(5, 9, '2016-03-11', 21345, 20000),
(6, 11, '2016-02-19', 22000, 21112),
(7, 12, '2016-01-28', 12890, 10000);

-- --------------------------------------------------------

--
-- Table structure for table `login`
--

CREATE TABLE `login` (
  `username` varchar(10) NOT NULL,
  `password` varchar(25) NOT NULL,
  `owner` varchar(30) NOT NULL,
  `address` varchar(100) NOT NULL,
  `balance` int(11) NOT NULL,
  `no_of_emp` int(11) NOT NULL,
  `Name` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `login`
--

INSERT INTO `login` (`username`, `password`, `owner`, `address`, `balance`, `no_of_emp`, `Name`) VALUES
('jeet', 'qwertyui', 'Jeet Mehta', 'JEET MEHTA, MEGASYSTEMS INC, SUITE 5A-1204, 799 E DRAGRAM, TUCSON AZ 85705, USA', 5022000, 25, 'Art Attack'),
('pranay', 'q', 'Pranay Patil', 'PRANAY PATIL, 100 MAIN ST, PO BOX 1022, SEATTLE WA 98104, USA', 7474000, 27, 'Dusty Modern'),
('prathamesh', 'qwertyui', 'Prathamesh Mhatre', 'PRATHAMESH MHATRE, 200 E MAIN ST, PHOENIX AZ 85123, USA', 4504000, 20, 'Z Gallery');

-- --------------------------------------------------------

--
-- Table structure for table `painting`
--

CREATE TABLE `painting` (
  `pid` int(11) NOT NULL,
  `name` varchar(25) NOT NULL,
  `medium` varchar(25) NOT NULL,
  `subject` varchar(25) NOT NULL,
  `area` int(11) NOT NULL,
  `id` int(11) NOT NULL,
  `sold_by` varchar(10) DEFAULT NULL,
  `sold_to` varchar(10) DEFAULT NULL,
  `current_artstore` varchar(30) NOT NULL,
  `url` varchar(100) NOT NULL,
  `century` int(11) NOT NULL,
  `date` date DEFAULT NULL,
  `price` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `painting`
--

INSERT INTO `painting` (`pid`, `name`, `medium`, `subject`, `area`, `id`, `sold_by`, `sold_to`, `current_artstore`, `url`, `century`, `date`, `price`) VALUES
(1, 'Rose', 'oil', 'potrait', 10000, 1, 'pranay', 'jeet', 'Art Attack', 'rose.jpeg', 20, '2016-03-20', 13200),
(2, 'Lily', 'oil', 'potrait', 10020, 2, 'pranay', 'pranay', 'Dusty Modern', 'lily.jpeg', 19, '2015-09-18', 13000),
(3, 'Sunflower', 'oil', 'potrait', 13000, 3, 'jeet', 'prathamesh', 'Z Gallery', 'sunflower.jpeg', 19, '2015-11-19', 15890),
(4, 'Bike', 'water', 'still-life', 9000, 1, 'pranay', 'jeet', 'Art Attack', 'bike.jpeg', 20, '2015-08-12', 29000),
(5, 'Car', 'water', 'still-life', 12450, 2, 'prathamesh', 'pranay', 'Dusty Modern', 'car.jpeg', 20, '2015-07-26', 13980),
(6, 'Aeroplane', 'water', 'still-life', 11230, 3, 'pranay', 'prathamesh', 'Z Gallery', 'aeroplane.jpeg', 20, '2015-02-13', 14500),
(7, 'Village Life', 'color', 'landscape', 20006, 1, 'jeet', 'prathamesh', 'Z Gallery', 'village_life.jpeg', 19, '2016-03-21', 24000),
(8, 'City Life', 'color', 'landscape', 12900, 2, 'prathamesh', 'pranay', 'Dusty Modern', 'city_life.jpeg', 19, '2016-02-19', 31689),
(9, 'Empty Room', 'color', 'landscape', 23001, 3, 'jeet', 'prathamesh', 'Z Gallery', 'empty_room.jpeg', 19, '2016-03-11', 21345),
(10, 'Child Playing', 'color', 'landscape', 9800, 1, 'prathamesh', 'jeet', 'Art Attack', 'child_playing.jpeg', 18, '2015-07-13', 29000),
(11, 'Fire Crackers', 'oil', 'potrait', 12000, 1, 'prathamesh', 'pranay', 'Dusty Modern', 'fire_crackers.jpeg', 20, '2016-03-20', 23000),
(12, 'Football Match', 'color', 'landscape', 15000, 2, 'jeet', 'pranay', 'Dusty Modern', 'football.jpeg', 20, '2016-01-28', 12890),
(13, 'Independence Day', 'water', 'landscape', 25000, 3, 'pranay', 'prathamesh', 'Z Gallery', 'independence_day.jpeg', 19, '2015-08-16', 14234),
(14, 'Sachin Tendulakar', 'oil', 'potrait', 9000, 1, 'pranay', 'jeet', 'Art Attack', 'sachin.jpeg', 20, '2015-09-21', 16538),
(15, 'Holi', 'water', 'landscape', 14500, 2, 'prathamesh', 'jeet', 'Art Attack', 'holi.jpeg', 19, '2015-04-27', 14632),
(16, 'Abstract Art', 'water', 'still-life', 12890, 3, 'prathamesh', 'pranay', 'Dusty Modern', 'abstarct.jpeg', 18, '2016-03-21', 25000);

-- --------------------------------------------------------

--
-- Table structure for table `pranay_available`
--

CREATE TABLE `pranay_available` (
  `pid` int(11) NOT NULL,
  `sell` tinyint(1) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `pranay_available`
--

INSERT INTO `pranay_available` (`pid`, `sell`) VALUES
(2, 1),
(5, 1),
(8, 1),
(11, 0),
(12, 0),
(16, 0);

-- --------------------------------------------------------

--
-- Table structure for table `pranay_purchased`
--

CREATE TABLE `pranay_purchased` (
  `no` int(11) NOT NULL,
  `pid` int(11) NOT NULL,
  `date` date NOT NULL,
  `p_price` int(25) NOT NULL,
  `opt_price` int(25) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `pranay_purchased`
--

INSERT INTO `pranay_purchased` (`no`, `pid`, `date`, `p_price`, `opt_price`) VALUES
(1, 1, '2016-03-20', 13000, 12164),
(2, 2, '2015-09-18', 13000, 12000),
(3, 5, '2015-07-26', 13980, 14000),
(4, 8, '2016-02-19', 31689, 30000),
(5, 11, '2016-03-20', 23000, 22150),
(6, 12, '2016-01-28', 12890, 10000),
(7, 16, '2015-08-23', 22000, 21000),
(8, 16, '2016-03-21', 25000, 33333);

-- --------------------------------------------------------

--
-- Table structure for table `pranay_sold`
--

CREATE TABLE `pranay_sold` (
  `no` int(11) NOT NULL,
  `pid` int(11) NOT NULL,
  `date` date NOT NULL,
  `s_price` int(11) NOT NULL,
  `opt_price` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `pranay_sold`
--

INSERT INTO `pranay_sold` (`no`, `pid`, `date`, `s_price`, `opt_price`) VALUES
(1, 2, '2015-09-18', 13000, 12000),
(2, 4, '2015-08-12', 29000, 27800),
(3, 6, '2015-02-13', 14500, 14890),
(4, 13, '2015-08-16', 14234, 27800),
(5, 14, '2015-09-21', 16538, 15890),
(6, 16, '2016-03-20', 15000, 22916),
(7, 16, '2016-03-21', 20000, 25000);

-- --------------------------------------------------------

--
-- Table structure for table `prathamesh_available`
--

CREATE TABLE `prathamesh_available` (
  `pid` int(11) NOT NULL,
  `sell` tinyint(1) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `prathamesh_available`
--

INSERT INTO `prathamesh_available` (`pid`, `sell`) VALUES
(3, 1),
(6, 1),
(7, 0),
(9, 0),
(13, 0);

-- --------------------------------------------------------

--
-- Table structure for table `prathamesh_purchased`
--

CREATE TABLE `prathamesh_purchased` (
  `no` int(11) NOT NULL,
  `pid` int(11) NOT NULL,
  `date` date NOT NULL,
  `p_price` int(25) NOT NULL,
  `opt_price` int(25) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `prathamesh_purchased`
--

INSERT INTO `prathamesh_purchased` (`no`, `pid`, `date`, `p_price`, `opt_price`) VALUES
(1, 3, '2015-11-19', 15890, 14000),
(2, 6, '2015-02-13', 14500, 14890),
(3, 7, '2016-03-21', 24000, 37846),
(4, 9, '2016-03-11', 21345, 20000),
(5, 11, '2016-02-19', 22000, 21112),
(6, 13, '2015-08-16', 14234, 14500),
(7, 16, '2016-03-21', 20000, 25000);

-- --------------------------------------------------------

--
-- Table structure for table `prathamesh_sold`
--

CREATE TABLE `prathamesh_sold` (
  `no` int(11) NOT NULL,
  `pid` int(11) NOT NULL,
  `date` date NOT NULL,
  `s_price` int(11) NOT NULL,
  `opt_price` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `prathamesh_sold`
--

INSERT INTO `prathamesh_sold` (`no`, `pid`, `date`, `s_price`, `opt_price`) VALUES
(1, 1, '2015-12-28', 12000, 12500),
(2, 5, '2015-07-26', 13980, 14000),
(3, 8, '2016-02-19', 31689, 30000),
(4, 10, '2015-07-13', 29000, 29000),
(5, 11, '2016-03-20', 23000, 22150),
(6, 15, '2015-04-27', 14632, 12000),
(7, 16, '2015-08-23', 22000, 21000),
(8, 16, '2016-03-21', 25000, 33333);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `artist`
--
ALTER TABLE `artist`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `available`
--
ALTER TABLE `available`
  ADD PRIMARY KEY (`pid`);

--
-- Indexes for table `jeet_available`
--
ALTER TABLE `jeet_available`
  ADD PRIMARY KEY (`pid`);

--
-- Indexes for table `jeet_purchased`
--
ALTER TABLE `jeet_purchased`
  ADD PRIMARY KEY (`no`,`pid`),
  ADD KEY `jeet_purchased_ibfk_1` (`pid`);

--
-- Indexes for table `jeet_sold`
--
ALTER TABLE `jeet_sold`
  ADD PRIMARY KEY (`no`,`pid`),
  ADD KEY `jeet_sold_ibfk_1` (`pid`);

--
-- Indexes for table `login`
--
ALTER TABLE `login`
  ADD PRIMARY KEY (`username`);

--
-- Indexes for table `painting`
--
ALTER TABLE `painting`
  ADD PRIMARY KEY (`pid`),
  ADD KEY `fk_user` (`id`);

--
-- Indexes for table `pranay_available`
--
ALTER TABLE `pranay_available`
  ADD PRIMARY KEY (`pid`);

--
-- Indexes for table `pranay_purchased`
--
ALTER TABLE `pranay_purchased`
  ADD PRIMARY KEY (`no`,`pid`),
  ADD KEY `pranay_purchased_ibfk_1` (`pid`);

--
-- Indexes for table `pranay_sold`
--
ALTER TABLE `pranay_sold`
  ADD PRIMARY KEY (`no`,`pid`),
  ADD KEY `pranay_sold_ibfk_1` (`pid`);

--
-- Indexes for table `prathamesh_available`
--
ALTER TABLE `prathamesh_available`
  ADD PRIMARY KEY (`pid`);

--
-- Indexes for table `prathamesh_purchased`
--
ALTER TABLE `prathamesh_purchased`
  ADD PRIMARY KEY (`no`,`pid`),
  ADD KEY `prathamesh_purchased_ibfk_1` (`pid`);

--
-- Indexes for table `prathamesh_sold`
--
ALTER TABLE `prathamesh_sold`
  ADD PRIMARY KEY (`no`,`pid`),
  ADD KEY `prathamesh_sold_ibfk_1` (`pid`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `jeet_purchased`
--
ALTER TABLE `jeet_purchased`
  MODIFY `no` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;
--
-- AUTO_INCREMENT for table `jeet_sold`
--
ALTER TABLE `jeet_sold`
  MODIFY `no` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;
--
-- AUTO_INCREMENT for table `pranay_purchased`
--
ALTER TABLE `pranay_purchased`
  MODIFY `no` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;
--
-- AUTO_INCREMENT for table `pranay_sold`
--
ALTER TABLE `pranay_sold`
  MODIFY `no` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;
--
-- AUTO_INCREMENT for table `prathamesh_purchased`
--
ALTER TABLE `prathamesh_purchased`
  MODIFY `no` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;
--
-- AUTO_INCREMENT for table `prathamesh_sold`
--
ALTER TABLE `prathamesh_sold`
  MODIFY `no` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;
--
-- Constraints for dumped tables
--

--
-- Constraints for table `available`
--
ALTER TABLE `available`
  ADD CONSTRAINT `available_ibfk_1` FOREIGN KEY (`pid`) REFERENCES `painting` (`pid`);

--
-- Constraints for table `jeet_available`
--
ALTER TABLE `jeet_available`
  ADD CONSTRAINT `jeet_available_ibfk_1` FOREIGN KEY (`pid`) REFERENCES `painting` (`pid`);

--
-- Constraints for table `jeet_purchased`
--
ALTER TABLE `jeet_purchased`
  ADD CONSTRAINT `jeet_purchased_ibfk_1` FOREIGN KEY (`pid`) REFERENCES `painting` (`pid`);

--
-- Constraints for table `jeet_sold`
--
ALTER TABLE `jeet_sold`
  ADD CONSTRAINT `jeet_sold_ibfk_1` FOREIGN KEY (`pid`) REFERENCES `painting` (`pid`);

--
-- Constraints for table `painting`
--
ALTER TABLE `painting`
  ADD CONSTRAINT `painting_ibfk_1` FOREIGN KEY (`id`) REFERENCES `artist` (`id`);

--
-- Constraints for table `pranay_available`
--
ALTER TABLE `pranay_available`
  ADD CONSTRAINT `pranay_available_ibfk_1` FOREIGN KEY (`pid`) REFERENCES `painting` (`pid`);

--
-- Constraints for table `pranay_purchased`
--
ALTER TABLE `pranay_purchased`
  ADD CONSTRAINT `pranay_purchased_ibfk_1` FOREIGN KEY (`pid`) REFERENCES `painting` (`pid`);

--
-- Constraints for table `pranay_sold`
--
ALTER TABLE `pranay_sold`
  ADD CONSTRAINT `pranay_sold_ibfk_1` FOREIGN KEY (`pid`) REFERENCES `painting` (`pid`);

--
-- Constraints for table `prathamesh_available`
--
ALTER TABLE `prathamesh_available`
  ADD CONSTRAINT `prathamesh_available_ibfk_1` FOREIGN KEY (`pid`) REFERENCES `painting` (`pid`);

--
-- Constraints for table `prathamesh_purchased`
--
ALTER TABLE `prathamesh_purchased`
  ADD CONSTRAINT `prathamesh_purchased_ibfk_1` FOREIGN KEY (`pid`) REFERENCES `painting` (`pid`);

--
-- Constraints for table `prathamesh_sold`
--
ALTER TABLE `prathamesh_sold`
  ADD CONSTRAINT `prathamesh_sold_ibfk_1` FOREIGN KEY (`pid`) REFERENCES `painting` (`pid`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
