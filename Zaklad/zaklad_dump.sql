/*M!999999\- enable the sandbox mode */ 
-- MariaDB dump 10.19-11.6.2-MariaDB, for Linux (x86_64)
--
-- Host: localhost    Database: Zaklad_mechaniczny
-- ------------------------------------------------------
-- Server version	11.6.2-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*M!100616 SET @OLD_NOTE_VERBOSITY=@@NOTE_VERBOSITY, NOTE_VERBOSITY=0 */;

--
-- Table structure for table `Czesci_zamienne`
--

DROP TABLE IF EXISTS `Czesci_zamienne`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Czesci_zamienne` (
  `id_czesci` int(11) NOT NULL AUTO_INCREMENT,
  `nazwa_czesci_zamiennej` varchar(255) DEFAULT NULL,
  `marka_pojazdu` varchar(80) DEFAULT NULL,
  `ilosc_sztuk` int(11) DEFAULT NULL,
  `cena_netto` double DEFAULT NULL,
  `cena_brutto` double DEFAULT NULL,
  PRIMARY KEY (`id_czesci`)
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Czesci_zamienne`
--

LOCK TABLES `Czesci_zamienne` WRITE;
/*!40000 ALTER TABLE `Czesci_zamienne` DISABLE KEYS */;
INSERT INTO `Czesci_zamienne` VALUES
(1,'Płyn hamulcowy FEBI BILSTEIN','AUDI',2,19.35,23.8),
(2,'Zestaw uszczelek, chłodnica olejowa ELRING 634.970','BMW',8,19.94,24.53),
(3,'Ochrona chłodnicy przed zamarzaniem','ALL',3,29.56,36.36),
(4,'Śruba, tarcza hamulcowa','AUDI',13,6.15,7.56),
(5,'Tarcza hamulcowa MASTER-SPORT MS-24011201781SE-SET','AUDI',20,193.9,238.5),
(6,'Odpowietrznik zacisku hamulcowego','AUDI',34,1.71,2.1),
(7,'Przekaźnik wielofunkcyjny (12V, 25A) 46-71-0004/VEM','DACIA',2,120.57,148.3),
(8,'Opornik, wentylator wewnętrzny VAL509898','DACIA',1,128.64,158.23),
(9,'Osuszacz, klimatyzacja NRF 33187','TOYOTA',3,28.79,35.41),
(10,'Zawór rozprężny, klimatyzacja NRF 38772','TOYOTA',3,76.64,94.27),
(11,'Tarcza Hamulcowa BREMBO 09.5843.31','OPEL',8,124.54,153.18),
(12,'Zestaw klocków hamulcowych, hamulce tarczowe, klicki BREMBO P59051','OPEL',12,91.85,112.98);
/*!40000 ALTER TABLE `Czesci_zamienne` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Klienci`
--

DROP TABLE IF EXISTS `Klienci`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Klienci` (
  `id_klienta` int(11) NOT NULL AUTO_INCREMENT,
  `imie` varchar(50) DEFAULT NULL,
  `nazwisko` varchar(60) DEFAULT NULL,
  `nr_telefonu` int(11) DEFAULT NULL,
  PRIMARY KEY (`id_klienta`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Klienci`
--

LOCK TABLES `Klienci` WRITE;
/*!40000 ALTER TABLE `Klienci` DISABLE KEYS */;
INSERT INTO `Klienci` VALUES
(1,'Bartosz','Kowalski',123456789),
(2,'Anna','Nowakowska',123999000),
(3,'Piotr','Wiśniewski',234567890),
(4,'Katarzyna','Lewandowska',876543210),
(5,'Marek','Wójcik',112233445),
(6,'Joanna','Zielińska',223344556),
(7,'Tomasz','Kaczmarek',334455667),
(8,'Janusz','Błoński',123098765),
(9,'Janusz','Błoński',123098765),
(10,'Janusz','Błoński',123098765),
(11,'Augustyn','Poniatowski',123098456);
/*!40000 ALTER TABLE `Klienci` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `mechanicy`
--

DROP TABLE IF EXISTS `mechanicy`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mechanicy` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `imie` varchar(100) DEFAULT NULL,
  `nazwisko` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `mechanicy`
--

LOCK TABLES `mechanicy` WRITE;
/*!40000 ALTER TABLE `mechanicy` DISABLE KEYS */;
INSERT INTO `mechanicy` VALUES
(1,'Kamil','Walec'),
(2,'Michał','Kowalski'),
(3,'Kamil','Zieliński'),
(4,'Jan','Wiśniewski'),
(5,'Paweł','Lewandowski'),
(6,'Jakub','Kaczmarek'),
(7,'Tomasz','Wójcik'),
(8,'Jacek','Bazowski'),
(9,'Mateusz','Bazowski'),
(10,'Boromir','Maciejczak');
/*!40000 ALTER TABLE `mechanicy` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pojazdy`
--

DROP TABLE IF EXISTS `pojazdy`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `pojazdy` (
  `id_pojazdu` int(11) NOT NULL AUTO_INCREMENT,
  `id_klienta` int(11) DEFAULT NULL,
  `id_zlecenia` int(11) DEFAULT NULL,
  `marka_pojazdu` varchar(80) DEFAULT NULL,
  PRIMARY KEY (`id_pojazdu`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pojazdy`
--

LOCK TABLES `pojazdy` WRITE;
/*!40000 ALTER TABLE `pojazdy` DISABLE KEYS */;
INSERT INTO `pojazdy` VALUES
(1,1,1,'AUDI'),
(2,2,2,'BMW'),
(3,3,3,'TOYOTA'),
(4,4,4,'OPEL'),
(5,5,5,'AUDI'),
(6,6,6,'DACIA'),
(7,7,7,'TOYOTA');
/*!40000 ALTER TABLE `pojazdy` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `uslugi`
--

DROP TABLE IF EXISTS `uslugi`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `uslugi` (
  `id_uslugi` int(11) NOT NULL AUTO_INCREMENT,
  `nazwa_uslugi` varchar(255) DEFAULT NULL,
  `cena` double DEFAULT NULL,
  PRIMARY KEY (`id_uslugi`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `uslugi`
--

LOCK TABLES `uslugi` WRITE;
/*!40000 ALTER TABLE `uslugi` DISABLE KEYS */;
INSERT INTO `uslugi` VALUES
(1,'Wymiana oleju',150),
(2,'Wymiana filtrów',100),
(3,'Naprawa zawieszenia',300),
(4,'Wymiana klocków hamulcowych',200),
(5,'Naprawa układu hamulcowego',250),
(6,'Naprawa klimatyzacji',180),
(7,'Naprawa układu wydechowego',220);
/*!40000 ALTER TABLE `uslugi` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `wyceny`
--

DROP TABLE IF EXISTS `wyceny`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `wyceny` (
  `id_wyceny` int(11) NOT NULL AUTO_INCREMENT,
  `zlecenie_id` int(11) NOT NULL,
  `czesc_id` int(11) DEFAULT NULL,
  `usluga_id` int(11) DEFAULT NULL,
  `cena_czesci` double DEFAULT 0,
  `cena_uslugi` double DEFAULT 0,
  PRIMARY KEY (`id_wyceny`),
  KEY `zlecenie_id` (`zlecenie_id`),
  KEY `czesc_id` (`czesc_id`),
  KEY `usluga_id` (`usluga_id`),
  CONSTRAINT `wyceny_ibfk_1` FOREIGN KEY (`zlecenie_id`) REFERENCES `zlecenia` (`id`),
  CONSTRAINT `wyceny_ibfk_2` FOREIGN KEY (`czesc_id`) REFERENCES `Czesci_zamienne` (`id_czesci`),
  CONSTRAINT `wyceny_ibfk_3` FOREIGN KEY (`usluga_id`) REFERENCES `uslugi` (`id_uslugi`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `wyceny`
--

LOCK TABLES `wyceny` WRITE;
/*!40000 ALTER TABLE `wyceny` DISABLE KEYS */;
INSERT INTO `wyceny` VALUES
(1,1,1,NULL,23.8,250),
(2,1,2,NULL,24.53,250),
(3,2,3,1,36.36,150),
(4,3,5,2,238.5,180),
(5,4,4,3,7.56,200),
(6,5,6,4,238.5,300),
(7,6,8,5,148.3,220);
/*!40000 ALTER TABLE `wyceny` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `zlecenia`
--

DROP TABLE IF EXISTS `zlecenia`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `zlecenia` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `opis` varchar(255) DEFAULT NULL,
  `data_zlecenia` timestamp NULL DEFAULT current_timestamp(),
  `status_naprawy` varchar(80) DEFAULT NULL,
  `id_klienta` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `zlecenia`
--

LOCK TABLES `zlecenia` WRITE;
/*!40000 ALTER TABLE `zlecenia` DISABLE KEYS */;
INSERT INTO `zlecenia` VALUES
(1,'Naprawa układu hamulcowego','2025-01-30 13:53:28','W trakcie naprawy',1),
(2,'Wymiana oleju i filtrów','2025-01-30 13:53:28','Zakończona',2),
(3,'Naprawa klimatyzacji','2025-01-30 13:53:28','W trakcie naprawy',3),
(4,'Wymiana klocków hamulcowych','2025-01-30 13:53:28','Oczekuje na części',4),
(5,'Naprawa zawieszenia','2025-01-30 13:53:28','Zakończona',5),
(6,'Wymiana rozrządu','2025-01-30 13:53:28','Zakończona',6),
(7,'Naprawa układu wydechowego','2025-01-30 13:53:28','W trakcie naprawy',7);
/*!40000 ALTER TABLE `zlecenia` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `zlecenia_mechanicy`
--

DROP TABLE IF EXISTS `zlecenia_mechanicy`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `zlecenia_mechanicy` (
  `zlecenie_id` int(11) NOT NULL,
  `mechanik_id` int(11) NOT NULL,
  PRIMARY KEY (`zlecenie_id`,`mechanik_id`),
  KEY `mechanik_id` (`mechanik_id`),
  CONSTRAINT `zlecenia_mechanicy_ibfk_1` FOREIGN KEY (`zlecenie_id`) REFERENCES `zlecenia` (`id`),
  CONSTRAINT `zlecenia_mechanicy_ibfk_2` FOREIGN KEY (`mechanik_id`) REFERENCES `mechanicy` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `zlecenia_mechanicy`
--

LOCK TABLES `zlecenia_mechanicy` WRITE;
/*!40000 ALTER TABLE `zlecenia_mechanicy` DISABLE KEYS */;
INSERT INTO `zlecenia_mechanicy` VALUES
(1,1),
(2,1),
(1,2),
(2,3),
(3,4),
(7,4),
(3,5),
(4,5),
(5,6),
(6,7),
(2,8),
(2,10);
/*!40000 ALTER TABLE `zlecenia_mechanicy` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*M!100616 SET NOTE_VERBOSITY=@OLD_NOTE_VERBOSITY */;

-- Dump completed on 2025-02-01  1:53:05
