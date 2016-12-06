create database lab12_development;
create database lab12_test;
create database lab12_production;

use lab12_development;

create table books (
id int not null auto_increment,
accession_no int not null,
title varchar(80) not null,
authors text not null,
edition decimal(8, 2) not null,
publisher varchar(80) not null,
primary key(id)
);
