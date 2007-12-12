-- MySQL dump 10.11
--
-- Host: localhost    Database: calender
-- ------------------------------------------------------
-- Server version	5.0.38-Ubuntu_0ubuntu1.1-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `create_events`
--

DROP TABLE IF EXISTS `create_events`;
CREATE TABLE `create_events` (
  `event_id` int(11) NOT NULL auto_increment,
  `user_id` varchar(30) default NULL,
  `year` int(20) default NULL,
  `week` int(100) default NULL,
  `time` varchar(30) default NULL,
  `event` varchar(30) default NULL,
  `date` varchar(30) default NULL,
  PRIMARY KEY  (`event_id`)
) ENGINE=MyISAM AUTO_INCREMENT=7 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `create_events`
--

LOCK TABLES `create_events` WRITE;
/*!40000 ALTER TABLE `create_events` DISABLE KEYS */;
/*!40000 ALTER TABLE `create_events` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `customer_details`
--

DROP TABLE IF EXISTS `customer_details`;
CREATE TABLE `customer_details` (
  `user_id` varchar(20) NOT NULL default '',
  `User_name` varchar(20) default NULL,
  `Password` varchar(50) default NULL,
  `First_name` varchar(50) default NULL,
  `Last_name` varchar(50) default NULL,
  `Email` varchar(50) default NULL,
  `Address` varchar(50) default NULL,
  `Country` varchar(50) default NULL,
  `Postel_code` varchar(50) default NULL,
  PRIMARY KEY  (`user_id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `customer_details`
--

LOCK TABLES `customer_details` WRITE;
/*!40000 ALTER TABLE `customer_details` DISABLE KEYS */;
/*!40000 ALTER TABLE `customer_details` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2007-12-11 23:05:14
