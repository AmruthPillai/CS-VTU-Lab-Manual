-- Creating Author table

CREATE TABLE Author (
	authorid INT,
	name VARCHAR(30),
	city VARCHAR(30),
	country VARCHAR(30),
	PRIMARY KEY (authorid)
);

DESC Author;

-- Creating Publisher table

CREATE TABLE Publisher (
	publisherid INT,
	name VARCHAR(30),
	city VARCHAR(30),
	country VARCHAR(30),
	PRIMARY KEY (publisherid)
);

DESC Publisher;

-- Creating Book_Category table

CREATE TABLE Book_Category (
	categoryid INT ,
	description VARCHAR(30),
	PRIMARY KEY (categoryid)
);

DESC Book_Category;

-- Creating Book_Catalog table

CREATE TABLE Book_Catalog (
	bookid INT,
	title VARCHAR(30),
	authorid INT,
	publisherid INT,
	categoryid INT,
	yearofpublish INT,
	price INT,
	PRIMARY KEY (bookid),
	FOREIGN KEY (authorid) REFERENCES Author (authorid),
	FOREIGN KEY (publisherid) REFERENCES Publisher (publisherid),
	FOREIGN KEY (categoryid) REFERENCES Book_Category (categoryid)
);

DESC Book_Catalog;

-- Creating Order_Details table

CREATE TABLE Order_Details (
	orderno INT,
	bookid INT,
	quantity INT,
	PRIMARY KEY (orderno, bookid),
	FOREIGN KEY (bookid) REFERENCES Book_Catalog(bookid)
);

DESC Order_Details;
