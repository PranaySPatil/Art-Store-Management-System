-- phpMyAdmin SQL Dump
-- version 4.3.11
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Mar 20, 2016 at 02:23 PM
-- Server version: 5.6.24
-- PHP Version: 5.6.8

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `artstoremgmt`
--

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
('jeet', 'qwertyui', 'Jeet Mehta', 'JEET MEHTA, MEGASYSTEMS INC, SUITE 5A-1204, 799 E DRAGRAM, TUCSON AZ 85705, USA', 5000000, 25, 'Art Attack'),
('pranay', 'q', 'Pranay Patil', 'PRANAY PATIL, 100 MAIN ST, PO BOX 1022, SEATTLE WA 98104, USA', 7500000, 27, 'Dusty Modern'),
('prathmesh', 'qwertyui', 'Prathamesh Mhatre', 'P MHATRE, 200 E MAIN ST, PHOENIX AZ 85123, USA', 4500000, 20, 'Z Gallery');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `login`
--
ALTER TABLE `login`
  ADD PRIMARY KEY (`username`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
