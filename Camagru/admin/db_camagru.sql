-- phpMyAdmin SQL Dump
-- version 4.7.9
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Jun 07, 2018 at 05:57 AM
-- Server version: 5.7.21
-- PHP Version: 7.1.16

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `db_camagru`
--

CREATE DATABASE IF NOT EXISTS `db_camagru` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `db_camagru`;

--
-- Table structure for table `avatars`
--

CREATE TABLE `avatars` (
  `id` int(11) NOT NULL,
  `user` int(11) NOT NULL,
  `image` varchar(128) NOT NULL,
  `image_text` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `avatars`
--

INSERT INTO `avatars` (`id`, `user`, `image`, `image_text`) VALUES
(3, 3, 'sample0.jpg', 'avatar'),
(8, 2, 'sample0.jpg', 'avatar');

-- --------------------------------------------------------

--
-- Table structure for table `comments`
--

CREATE TABLE `comments` (
  `id` int(11) NOT NULL,
  `photo` int(11) NOT NULL,
  `user` varchar(128) NOT NULL,
  `content` varchar(256) NOT NULL,
  `posted` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `comments`
--

INSERT INTO `comments` (`id`, `photo`, `user`, `content`, `posted`) VALUES
(11, 3, 'jordie', 'cooool', '2018-06-02');

-- --------------------------------------------------------

--
-- Table structure for table `img`
--

CREATE TABLE `img` (
  `id` int(11) NOT NULL,
  `photo` varchar(128) NOT NULL,
  `user` int(11) NOT NULL,
  `likes` int(11) NOT NULL DEFAULT '0',
  `added` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `img`
--

INSERT INTO `img` (`id`, `photo`, `user`, `likes`, `added`) VALUES
(2, '1_MCB3491.jpg', 2, 0, '2018-06-07'),
(4, '_MCB9103.jpg', 2, 2, '2018-06-02'),
(5, 'DSC09905.jpg', 3, 2, '2018-06-02'),
(6, 'DSC_4688.jpg', 2, 1, '2018-06-04'),
(7, 'DSC_0077_2.jpg', 2, 1, '2018-06-04'),
(9, 'DSC_4672.jpg', 2, 1, '2018-06-04');

-- --------------------------------------------------------

--
-- Table structure for table `likes`
--

CREATE TABLE `likes` (
  `id` int(11) NOT NULL,
  `user` int(11) NOT NULL,
  `photo` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `likes`
--

INSERT INTO `likes` (`id`, `user`, `photo`) VALUES
(11, 3, 4),
(12, 3, 3),
(13, 3, 2),
(14, 3, 1),
(15, 3, 5),
(161, 2, 3),
(257, 2, 5),
(289, 2, 6),
(290, 2, 7),
(293, 2, 4),
(299, 2, 9);

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE `users` (
  `id` int(11) NOT NULL,
  `login` varchar(128) NOT NULL,
  `pwd` varchar(128) NOT NULL,
  `first` varchar(128) NOT NULL,
  `last` varchar(128) NOT NULL,
  `email` varchar(128) NOT NULL,
  `token` varchar(32) NOT NULL,
  `confirmed` int(11) NOT NULL DEFAULT '0',
  `joined` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`id`, `login`, `pwd`, `first`, `last`, `email`, `token`, `confirmed`, `joined`) VALUES
(2, 'mvaskiv', '7612e94c0f62a09b7fda696d52acfb0b6df7ac66f9f4b833107ec9874510606c3e58a68981eddd262c0ab4072e46e2cbd45f2e63c1c46e666ffc42fcb827b52d', 'mike', 'vaskiv', 'mike@vaskiv.com', 'fuckoffiamtheboss', 1, '2018-06-01'),
(3, 'jordie', 'ac5bbf8b24d2db584f0dcc26e738ec41f2fabb971851fb17aa3475587df5836346ea422378bdd654dafca3fe62033135dbec46b63b27fb4d13da78ee0e6bbe8d', 'jordie', 'jackson', '1@1.com', '', 0, '2018-06-02');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `avatars`
--
ALTER TABLE `avatars`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `comments`
--
ALTER TABLE `comments`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `img`
--
ALTER TABLE `img`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `likes`
--
ALTER TABLE `likes`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `avatars`
--
ALTER TABLE `avatars`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- AUTO_INCREMENT for table `comments`
--
ALTER TABLE `comments`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=23;

--
-- AUTO_INCREMENT for table `img`
--
ALTER TABLE `img`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- AUTO_INCREMENT for table `likes`
--
ALTER TABLE `likes`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=300;

--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=21;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
