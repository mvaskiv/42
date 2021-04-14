-- phpMyAdmin SQL Dump
-- version 4.7.9
-- https://www.phpmyadmin.net/
--
-- Хост: localhost:3306
-- Время создания: Апр 08 2018 г., 12:48
-- Версия сервера: 5.7.21
-- Версия PHP: 7.1.15

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- База данных: `db_shop`
--
CREATE DATABASE IF NOT EXISTS `db_shop` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `db_shop`;

-- --------------------------------------------------------

--
-- Структура таблицы `categories`
--

CREATE TABLE `categories` (
  `id` int(11) NOT NULL,
  `name` varchar(128) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `categories`
--

INSERT INTO `categories` (`id`, `name`) VALUES
(6, 'sofa'),
(7, 'chair'),
(8, 'table'),
(9, 'furniture'),
(10, 'lights'),
(11, 'shelvs'),
(12, 'bed'),
(13, 'living_room'),
(14, 'dinning_room'),
(16, 'bathroom'),
(18, 'bedroom');

-- --------------------------------------------------------

--
-- Структура таблицы `orders`
--

CREATE TABLE `orders` (
  `id` int(11) NOT NULL,
  `user_name` varchar(512) NOT NULL,
  `sum` decimal(10,0) NOT NULL,
  `purchase` json NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `orders`
--

INSERT INTO `orders` (`id`, `user_name`, `sum`, `purchase`) VALUES
(84, 'anna', '1300', '{\"sofa\": 2, \"chair\": 1}'),
(85, 'anna', '524', '{\"apple\": 2, \"table\": 1}'),
(86, 'anna', '1665', '{\"lamp\": 1, \"chair\": 1, \"table\": 1, \"banana\": 3}'),
(87, 'anna', '2100', '{\"chair\": 1, \"table\": 2}'),
(88, 'anna', '82', '{\"lamp\": 1, \"lime\": 3, \"banana\": 1}'),
(89, 'admin', '7350', '{\"lamp\": 1, \"sofa\": 3, \"chair\": 5, \"table\": 3}'),
(90, 'admin', '100', '{\"sofa\": 1}'),
(91, 'admin', '1100', '{\"chair\": 1}'),
(123, 'admin', '200', '{\"madonna\": 1}'),
(124, 'admin', '1150', '{\"prince\": 1, \"rudolfo\": 1, \"snow white\": 4, \"black chair\": 2}');

-- --------------------------------------------------------

--
-- Структура таблицы `products`
--

CREATE TABLE `products` (
  `id` int(11) NOT NULL,
  `name` varchar(128) NOT NULL,
  `price` decimal(10,0) NOT NULL,
  `picture` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `products`
--

INSERT INTO `products` (`id`, `name`, `price`, `picture`) VALUES
(15, 'snow', '100', 'img/goods/cahir.jpg'),
(16, 'blacky', '100', 'img/goods/chair2.jpg'),
(17, 'rudolfo', '250', 'img/goods/duckery1.jpg'),
(19, 'Brownie', '100', 'img/goods/fuckery.jpg'),
(21, 'Margarita', '900', 'img/goods/set.jpeg'),
(23, 'family', '700', 'img/goods/set2.jpeg'),
(24, 'Lazy', '650', 'img/goods/sofa.jpg'),
(25, 'Diamon', '1000', 'img/goods/sofa1.jpeg'),
(26, 'comfort', '450', 'img/goods/sofa3.jpg'),
(29, 'prince', '200', 'img/goods/bed.jpg'),
(30, 'grey', '400', 'img/goods/bed1.jpg'),
(31, 'fog', '700', 'img/goods/set1.jpg');

-- --------------------------------------------------------

--
-- Структура таблицы `product_category`
--

CREATE TABLE `product_category` (
  `productID` int(11) NOT NULL,
  `categoryID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `product_category`
--

INSERT INTO `product_category` (`productID`, `categoryID`) VALUES
(15, 14),
(16, 7),
(17, 11),
(17, 13),
(19, 11),
(19, 13),
(21, 14),
(21, 9),
(23, 9),
(23, 14),
(24, 6),
(24, 13),
(25, 6),
(25, 13),
(26, 6),
(26, 13),
(29, 12),
(29, 18),
(30, 12),
(30, 18),
(31, 9),
(31, 14);

-- --------------------------------------------------------

--
-- Структура таблицы `users`
--

CREATE TABLE `users` (
  `id` int(11) NOT NULL,
  `name` varchar(128) NOT NULL,
  `password` varchar(128) NOT NULL,
  `rights` varchar(128) NOT NULL DEFAULT 'buyer'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `users`
--

INSERT INTO `users` (`id`, `name`, `password`, `rights`) VALUES
(3, 'sveta', '1dbc95c77bdc73516f20b7a575221f67a183526c2bf4782333bc8b620a559376442409698f46cad0d3548c961995d9ef570dbf8e05709496c50a9f0b087f717c', 'buyer'),
(4, 'admin', '086794cfbe18b122c757ee481c4166d814b650e9d150920beb3f0e75a26df01be3ebe35cb879b237ad0dd263dfcb83cc6223755ea1e7cded7de8dfc139d55bbf', 'admin'),
(5, 'anna', 'd6ba3e6ab8745031057704342d48a38e80e6285e036eaa8dac3ce01f2419aa1ad0173a8e4e224b170830542ff09747ce37d1c9f39556a588ae159f5cd4517219', 'buyer'),
(19, 'olya', 'c50a28029da35915bffac933d11720dada97f2382f050ce908846d8ffed2190995a24a9112f2f6cd9c9ba9683c1bcd347f87bceff8de35d7b21f24136bd7dda0', 'buyer'),
(20, 'nastya', '148a59645eaed6228377430a4c4247bdd2db57303972b3ee385f55be18d26b8ae50fe4d10b4775791cae102ebafac8dd5f62f08cfc53632c93ad47388a672caa', 'buyer'),
(21, 'vasya', '1dbc95c77bdc73516f20b7a575221f67a183526c2bf4782333bc8b620a559376442409698f46cad0d3548c961995d9ef570dbf8e05709496c50a9f0b087f717c', 'buyer'),
(22, 'alya', 'd6ba3e6ab8745031057704342d48a38e80e6285e036eaa8dac3ce01f2419aa1ad0173a8e4e224b170830542ff09747ce37d1c9f39556a588ae159f5cd4517219', 'admin'),
(23, 'vova', '1dbc95c77bdc73516f20b7a575221f67a183526c2bf4782333bc8b620a559376442409698f46cad0d3548c961995d9ef570dbf8e05709496c50a9f0b087f717c', 'buyer'),
(24, 'vitya', 'a7101dfaf1ac55fe9fcfbb985f79ac46807f38f46582fd80911f796f398b8b1533dcb6bbfbf909b40472b6acbcaba75ade6cd116abea0aae72a81c32f8125caf', 'buyer'),
(25, 'james', '2fc57842fca09db4722796cd2b2761969c74628297a79a326ca071248ba2cb2139105994054fbb654e6e48079aa2c7b4bd20200c8dad194053896263e36b51c0', 'admin'),
(26, 'john', 'af85293f325ac3048b93e3170dff700db760d988d87317e31c546c2a1dee5c23ec4f169c8783b34b1f9653707918af654a9cd5f86ce059770ea8595b22716d73', 'buyer'),
(27, 'marry', 'ada04b5150bf7e40e70a3e56a78570319ac9a1ad6c117ea378318ae57423f995c8320e99e88f4d4bad3b336d17aaff1b13a4bb17ad972e1e738c655a9dd387ce', 'buyer'),
(28, 'oleg', 'aba086dbbcdf223f957dae740b5d2d374e993aa42ce96a1ca63d96d83e9deb2d28cd86c09e092a335e8ac8240b566ba08aac4df3ef35b28844c7692850147347', 'buyer'),
(29, 'brenda', '5335dab9f68c554b7eae0196df8aa6884d33d7fc11e9724298932a40a3cbf00debea495357685478c85bdaea49eb4d52f3af5a545c4ba31627b63714f39261cd', 'buyer'),
(30, 'david', '52ca0c18c563d3f7cc621bda12e652d03a741a0848cd53eb0b28e6c08403d0c07785a3ebc8cf2576f3bbaef5f809ceb5e974b843d65932b277f76c624441627a', 'buyer'),
(31, 'briab', '148a59645eaed6228377430a4c4247bdd2db57303972b3ee385f55be18d26b8ae50fe4d10b4775791cae102ebafac8dd5f62f08cfc53632c93ad47388a672caa', 'admin'),
(32, 'tracy', 'a7101dfaf1ac55fe9fcfbb985f79ac46807f38f46582fd80911f796f398b8b1533dcb6bbfbf909b40472b6acbcaba75ade6cd116abea0aae72a81c32f8125caf', 'buyer'),
(35, 'vika', '1dbc95c77bdc73516f20b7a575221f67a183526c2bf4782333bc8b620a559376442409698f46cad0d3548c961995d9ef570dbf8e05709496c50a9f0b087f717c', 'admin');

-- --------------------------------------------------------

--
-- Структура таблицы `users_orders`
--

CREATE TABLE `users_orders` (
  `user_name` varchar(128) NOT NULL,
  `orderID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `users_orders`
--

INSERT INTO `users_orders` (`user_name`, `orderID`) VALUES
('anna', 84),
('anna', 84),
('anna', 84),
('anna', 84),
('anna', 84),
('admin', 89),
('admin', 89),
('admin', 89),
('anna', 84),
('anna', 84),
('anna', 84),
('anna', 84),
('anna', 84),
('anna', 84),
('anna', 84),
('anna', 84),
('anna', 84),
('anna', 84),
('anna', 84),
('anna', 84),
('anna', 84),
('anna', 84),
('anna', 84),
('admin', 89),
('anna', 84),
('anna', 84),
('anna', 84),
('anna', 84),
('anna', 84),
('anna', 84),
('anna', 84),
('anna', 84),
('anna', 84),
('anna', 84),
('anna', 84),
('anna', 84),
('anna', 84),
('anna', 84),
('anna', 84),
('anna', 84),
('admin', 89),
('admin', 89);

--
-- Индексы сохранённых таблиц
--

--
-- Индексы таблицы `categories`
--
ALTER TABLE `categories`
  ADD PRIMARY KEY (`id`);

--
-- Индексы таблицы `orders`
--
ALTER TABLE `orders`
  ADD PRIMARY KEY (`id`);

--
-- Индексы таблицы `products`
--
ALTER TABLE `products`
  ADD PRIMARY KEY (`id`);

--
-- Индексы таблицы `product_category`
--
ALTER TABLE `product_category`
  ADD KEY `category_id_id` (`categoryID`),
  ADD KEY `id_product_id` (`productID`);

--
-- Индексы таблицы `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `name` (`name`);

--
-- Индексы таблицы `users_orders`
--
ALTER TABLE `users_orders`
  ADD KEY `id_order_id` (`orderID`),
  ADD KEY `name_user_name` (`user_name`);

--
-- AUTO_INCREMENT для сохранённых таблиц
--

--
-- AUTO_INCREMENT для таблицы `categories`
--
ALTER TABLE `categories`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=19;

--
-- AUTO_INCREMENT для таблицы `orders`
--
ALTER TABLE `orders`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=125;

--
-- AUTO_INCREMENT для таблицы `products`
--
ALTER TABLE `products`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=32;

--
-- AUTO_INCREMENT для таблицы `users`
--
ALTER TABLE `users`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=36;

--
-- Ограничения внешнего ключа сохраненных таблиц
--

--
-- Ограничения внешнего ключа таблицы `product_category`
--
ALTER TABLE `product_category`
  ADD CONSTRAINT `category_id_id` FOREIGN KEY (`categoryID`) REFERENCES `categories` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `id_product_id` FOREIGN KEY (`productID`) REFERENCES `products` (`id`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Ограничения внешнего ключа таблицы `users_orders`
--
ALTER TABLE `users_orders`
  ADD CONSTRAINT `id_order_id` FOREIGN KEY (`orderID`) REFERENCES `orders` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `name_user_name` FOREIGN KEY (`user_name`) REFERENCES `users` (`name`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
