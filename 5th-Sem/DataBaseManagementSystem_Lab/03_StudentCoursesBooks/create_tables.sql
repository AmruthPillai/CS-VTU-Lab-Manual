-- Creating Student table

CREATE TABLE Student (
	regno VARCHAR(30),
	sname VARCHAR(30),
	major VARCHAR(30),
	bdate DATE,
	PRIMARY KEY (regno)
); 

DESC Student;

-- Creating Course table

CREATE TABLE Course (
	courseno INT,
	cname VARCHAR(30),
	dept VARCHAR(30),
	PRIMARY KEY (courseno)
); 

DESC Course;

-- Creating Enroll table

CREATE TABLE Enroll (
	regno VARCHAR(30),
	courseno INT,
	sem INT,
	marks INT,
	PRIMARY KEY (regno, courseno),
	FOREIGN KEY (regno) REFERENCES Student(regno),
	FOREIGN KEY (courseno) REFERENCES Course(courseno)); 

DESC Enroll;

-- Creating Text table

CREATE TABLE Text (
	bookisbn INT,
	booktitle VARCHAR(30),
	publisher VARCHAR(30),
	author VARCHAR(30),
	PRIMARY KEY (bookisbn)
);

DESC Text;

-- Creating Book_Adoption table

CREATE TABLE Book_Adoption (
	courseno INT,
	sem INT,
	bookisbn INT,
	PRIMARY KEY (courseno, bookisbn),
	FOREIGN KEY (courseno) REFERENCES Course (courseno),
	FOREIGN KEY (bookisbn) REFERENCES Text (bookisbn)
); 

DESC Book_Adoption;
