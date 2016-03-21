-- phpMyAdmin SQL Dump
-- version 4.3.11
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Mar 20, 2016 at 05:24 PM
-- Server version: 5.6.24
-- PHP Version: 5.6.8

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `artstoremgmtsys2`
--

-- --------------------------------------------------------

--
-- Table structure for table `artist`
--

CREATE TABLE IF NOT EXISTS `artist` (
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

CREATE TABLE IF NOT EXISTS `available` (
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
(7, 24000),
(8, 33000);

-- --------------------------------------------------------

--
-- Table structure for table `jeet_available`
--

CREATE TABLE IF NOT EXISTS `jeet_available` (
  `pid` int(11) NOT NULL,
  `sell` tinyint(1) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `jeet_available`
--

INSERT INTO `jeet_available` (`pid`, `sell`) VALUES
(1, 0),
(4, 1),
(7, 1),
(10, 0),
(14, 0),
(15, 0);

-- --------------------------------------------------------

--
-- Table structure for table `jeet_purchased`
--

CREATE TABLE IF NOT EXISTS `jeet_purchased` (
  `pid` int(11) NOT NULL,
  `date` date NOT NULL,
  `p_price` int(25) NOT NULL,
  `opt_price` int(25) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `jeet_purchased`
--

INSERT INTO `jeet_purchased` (`pid`, `date`, `p_price`, `opt_price`) VALUES
(1, '2015-12-28', 12000, 12500),
(4, '2015-08-12', 29000, 27800),
(7, '2016-01-12', 24890, 23000),
(10, '2015-07-13', 29000, 29000),
(14, '2015-09-21', 16538, 15890),
(15, '2015-04-27', 14632, 12000),
(16, '2016-03-20', 15000, 22916);

-- --------------------------------------------------------

--
-- Table structure for table `jeet_sold`
--

CREATE TABLE IF NOT EXISTS `jeet_sold` (
  `pid` int(11) NOT NULL,
  `date` date NOT NULL,
  `s_price` int(11) NOT NULL,
  `opt_price` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `jeet_sold`
--

INSERT INTO `jeet_sold` (`pid`, `date`, `s_price`, `opt_price`) VALUES
(1, '2016-03-20', 13000, 12164),
(3, '2015-11-19', 15890, 14000),
(7, '2016-01-12', 24890, 23000),
(9, '2016-03-11', 21345, 20000),
(11, '2016-02-19', 22000, 21112),
(12, '2016-01-28', 12890, 10000);

-- --------------------------------------------------------

--
-- Table structure for table `login`
--

CREATE TABLE IF NOT EXISTS `login` (
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
('jeet', 'qwertyui', 'Jeet Mehta', 'JEET MEHTA, MEGASYSTEMS INC, SUITE 5A-1204, 799 E DRAGRAM, TUCSON AZ 85705, USA', 4998000, 25, 'Art Attack'),
('pranay', 'q', 'Pranay Patil', 'PRANAY PATIL, 100 MAIN ST, PO BOX 1022, SEATTLE WA 98104, USA', 7479000, 27, 'Dusty Modern'),
('prathmesh', 'qwertyui', 'Prathamesh Mhatre', 'P MHATRE, 200 E MAIN ST, PHOENIX AZ 85123, USA', 4523000, 20, 'Z Gallery');

-- --------------------------------------------------------

--
-- Table structure for table `painting`
--

CREATE TABLE IF NOT EXISTS `painting` (
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
(3, 'Sunflower', 'oil', 'potrait', 13000, 3, 'jeet', 'prathmesh', 'Z Gallery', 'sunflower.jpeg', 19, '2015-11-19', 15890),
(4, 'Bike', 'water', 'still-life', 9000, 1, 'pranay', 'jeet', 'Art Attack', 'bike.jpeg', 20, '2015-08-12', 29000),
(5, 'Car', 'water', 'still-life', 12450, 2, 'prathmesh', 'pranay', 'Dusty Modern', 'car.jpeg', 20, '2015-07-26', 13980),
(6, 'Aeroplane', 'water', 'still-life', 11230, 3, 'pranay', 'prathmesh', 'Z Gallery', 'aeroplane.jpeg', 20, '2015-02-13', 14500),
(7, 'Village Life', 'color', 'landscape', 20006, 1, 'jeet', 'jeet', 'Art Attack', 'village_life.jpeg', 19, '2016-01-12', 24890),
(8, 'City Life', 'color', 'landscape', 12900, 2, 'prathmesh', 'pranay', 'Dusty Modern', 'city_life.jpeg', 19, '2016-02-19', 31689),
(9, 'Empty Room', 'color', 'landscape', 23001, 3, 'jeet', 'prathmesh', 'Z Gallery', 'empty_room.jpeg', 19, '2016-03-11', 21345),
(10, 'Child Playing', 'color', 'landscape', 9800, 1, 'prathmesh', 'jeet', 'Art Attack', 'child_playing.jpeg', 18, '2015-07-13', 29000),
(11, 'Fire Crackers', 'oil', 'potrait', 12000, 1, 'prathmesh', 'pranay', 'Dusty Modern', 'fire_crackers.jpeg', 20, '2016-03-20', 23000),
(12, 'Football Match', 'color', 'landscape', 15000, 2, 'jeet', 'pranay', 'Dusty Modern', 'football.jpeg', 20, '2016-01-28', 12890),
(13, 'Independence Day', 'water', 'landscape', 25000, 3, 'pranay', 'prathmesh', 'Z Gallery', 'independence_day.jpeg', 19, '2015-08-16', 14234),
(14, 'Sachin Tendulakar', 'oil', 'potrait', 9000, 1, 'pranay', 'jeet', 'Art Attack', 'sachin.jpeg', 20, '2015-09-21', 16538),
(15, 'Holi', 'water', 'landscape', 14500, 2, 'prathmesh', 'jeet', 'Art Attack', 'holi.jpeg', 19, '2015-04-27', 14632),
(16, 'Abstract Art', 'water', 'still-life', 12890, 3, 'jeet', 'pranay', 'Dusty Modern', 'abstarct.jpeg', 18, '2016-03-20', 15000);

-- --------------------------------------------------------

--
-- Table structure for table `pranay_available`
--

CREATE TABLE IF NOT EXISTS `pranay_available` (
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

CREATE TABLE IF NOT EXISTS `pranay_purchased` (
  `pid` int(11) NOT NULL,
  `date` date NOT NULL,
  `p_price` int(25) NOT NULL,
  `opt_price` int(25) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `pranay_purchased`
--

INSERT INTO `pranay_purchased` (`pid`, `date`, `p_price`, `opt_price`) VALUES
(1, '2016-03-20', 13000, 12164),
(2, '2015-09-18', 13000, 12000),
(5, '2015-07-26', 13980, 14000),
(8, '2016-02-19', 31689, 30000),
(11, '2016-03-20', 23000, 22150),
(12, '2016-01-28', 12890, 10000),
(16, '2015-08-23', 22000, 21000);

-- --------------------------------------------------------

--
-- Table structure for table `pranay_sold`
--

CREATE TABLE IF NOT EXISTS `pranay_sold` (
  `pid` int(11) NOT NULL,
  `date` date NOT NULL,
  `s_price` int(11) NOT NULL,
  `opt_price` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `pranay_sold`
--

INSERT INTO `pranay_sold` (`pid`, `date`, `s_price`, `opt_price`) VALUES
(2, '2015-09-18', 13000, 12000),
(4, '2015-08-12', 29000, 27800),
(6, '2015-02-13', 14500, 14890),
(13, '2015-08-16', 14234, 27800),
(14, '2015-09-21', 16538, 15890),
(16, '2016-03-20', 15000, 22916);

-- --------------------------------------------------------

--
-- Table structure for table `prathmesh_available`
--

CREATE TABLE IF NOT EXISTS `prathmesh_available` (
  `pid` int(11) NOT NULL,
  `sell` tinyint(1) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `prathmesh_available`
--

INSERT INTO `prathmesh_available` (`pid`, `sell`) VALUES
(3, 1),
(6, 1),
(9, 0),
(13, 0);

-- --------------------------------------------------------

--
-- Table structure for table `prathmesh_purchased`
--

CREATE TABLE IF NOT EXISTS `prathmesh_purchased` (
  `pid` int(11) NOT NULL,
  `date` date NOT NULL,
  `p_price` int(25) NOT NULL,
  `opt_price` int(25) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `prathmesh_purchased`
--

INSERT INTO `prathmesh_purchased` (`pid`, `date`, `p_price`, `opt_price`) VALUES
(3, '2015-11-19', 15890, 14000),
(6, '2015-02-13', 14500, 14890),
(9, '2016-03-11', 21345, 20000),
(11, '2016-02-19', 22000, 21112),
(13, '2015-08-16', 14234, 14500);

-- --------------------------------------------------------

--
-- Table structure for table `prathmesh_sold`
--

CREATE TABLE IF NOT EXISTS `prathmesh_sold` (
  `pid` int(11) NOT NULL,
  `date` date NOT NULL,
  `s_price` int(11) NOT NULL,
  `opt_price` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `prathmesh_sold`
--

INSERT INTO `prathmesh_sold` (`pid`, `date`, `s_price`, `opt_price`) VALUES
(1, '2015-12-28', 12000, 12500),
(5, '2015-07-26', 13980, 14000),
(8, '2016-02-19', 31689, 30000),
(10, '2015-07-13', 29000, 29000),
(11, '2016-03-20', 23000, 22150),
(15, '2015-04-27', 14632, 12000),
(16, '2015-08-23', 22000, 21000);

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
  ADD PRIMARY KEY (`pid`);

--
-- Indexes for table `jeet_sold`
--
ALTER TABLE `jeet_sold`
  ADD PRIMARY KEY (`pid`);

--
-- Indexes for table `login`
--
ALTER TABLE `login`
  ADD PRIMARY KEY (`username`);

--
-- Indexes for table `painting`
--
ALTER TABLE `painting`
  ADD PRIMARY KEY (`pid`), ADD KEY `fk_user` (`id`);

--
-- Indexes for table `pranay_available`
--
ALTER TABLE `pranay_available`
  ADD PRIMARY KEY (`pid`);

--
-- Indexes for table `pranay_purchased`
--
ALTER TABLE `pranay_purchased`
  ADD PRIMARY KEY (`pid`);

--
-- Indexes for table `pranay_sold`
--
ALTER TABLE `pranay_sold`
  ADD PRIMARY KEY (`pid`);

--
-- Indexes for table `prathmesh_available`
--
ALTER TABLE `prathmesh_available`
  ADD PRIMARY KEY (`pid`);

--
-- Indexes for table `prathmesh_purchased`
--
ALTER TABLE `prathmesh_purchased`
  ADD PRIMARY KEY (`pid`);

--
-- Indexes for table `prathmesh_sold`
--
ALTER TABLE `prathmesh_sold`
  ADD PRIMARY KEY (`pid`);

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
-- Constraints for table `prathmesh_available`
--
ALTER TABLE `prathmesh_available`
ADD CONSTRAINT `prathmesh_available_ibfk_1` FOREIGN KEY (`pid`) REFERENCES `painting` (`pid`);

--
-- Constraints for table `prathmesh_purchased`
--
ALTER TABLE `prathmesh_purchased`
ADD CONSTRAINT `prathmesh_purchased_ibfk_1` FOREIGN KEY (`pid`) REFERENCES `painting` (`pid`);

--
-- Constraints for table `prathmesh_sold`
--
ALTER TABLE `prathmesh_sold`
ADD CONSTRAINT `prathmesh_sold_ibfk_1` FOREIGN KEY (`pid`) REFERENCES `painting` (`pid`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
