-- MySQL dump 10.11
--
-- Host: localhost    Database: Calendar
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
-- Table structure for table `customer_details`
--

DROP TABLE IF EXISTS `customer_details`;
CREATE TABLE `customer_details` (
  `user_id` int(50) NOT NULL auto_increment,
  `user_name` varchar(20) NOT NULL,
  `password` varchar(50) default NULL,
  `first_name` varchar(50) default NULL,
  `last_name` varchar(50) default NULL,
  `email` varchar(50) default NULL,
  `address` varchar(50) default NULL,
  `country` varchar(50) default NULL,
  `postel_code` varchar(50) default NULL,
  `session_id` varchar(50) default NULL,
  `last_accessed_datetime` varchar(50) default NULL,
  PRIMARY KEY  (`user_id`),
  UNIQUE KEY `user_name` (`user_name`)
) ENGINE=MyISAM AUTO_INCREMENT=24 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `customer_details`
--

LOCK TABLES `customer_details` WRITE;
/*!40000 ALTER TABLE `customer_details` DISABLE KEYS */;
INSERT INTO `customer_details` VALUES (23,'Amal','aaa','Amal','Weerarathna','to@fwer.com','Gampaha','SriLanka','112',NULL,NULL);
/*!40000 ALTER TABLE `customer_details` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `events`
--

DROP TABLE IF EXISTS `events`;
CREATE TABLE `events` (
  `start_time` varchar(20) default NULL,
  `end_time` varchar(50) default NULL,
  `name` varchar(50) default NULL,
  `description` varchar(50) default NULL,
  `user_id` varchar(30) default NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `events`
--

LOCK TABLES `events` WRITE;
/*!40000 ALTER TABLE `events` DISABLE KEYS */;
INSERT INTO `events` VALUES ('2008-04-08 11:30:00','2008-04-08 11:45:00','party','There is a party at 2 pm','23');
/*!40000 ALTER TABLE `events` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2008-02-20 18:10:33
