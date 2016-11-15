-- Creating Branch table

CREATE TABLE Branch (
	branchname VARCHAR(30),
	branchcity VARCHAR(30),
	assets REAL,
	PRIMARY KEY (branchname)
);

DESC Branch;

-- Creating Account table

CREATE TABLE Account (
	accno INT,
	branchname VARCHAR(30),
	balance REAL,
	PRIMARY KEY (accno),
	FOREIGN KEY (branchname) REFERENCES Branch (branchname)
);

DESC Account;

-- Creating Customer table

CREATE TABLE Customer (
	customername VARCHAR(30),
	customerstreet VARCHAR(30),
	customercity VARCHAR(30),
	PRIMARY KEY (customername)
);

DESC Customer;

-- Creating Depositor table

CREATE TABLE Depositor (
	customername VARCHAR(30),
	accno INT,
	PRIMARY KEY (customername, accno),
	FOREIGN KEY (customername) REFERENCES Customer (customername),
	FOREIGN KEY (accno) REFERENCES Account (accno)
);

DESC Depositor;

-- Creating Loan table

CREATE TABLE Loan (
	loannumber INT,
	branchname VARCHAR(30),
	amount REAL,
	PRIMARY KEY (loannumber),
	FOREIGN KEY (branchname) REFERENCES Branch (branchname)
);

DESC Loan;

-- Creating Borrower table

CREATE TABLE Borrower (
	customername VARCHAR(30),
	loannumber INT,
	PRIMARY KEY (customername, loannumber),
	FOREIGN KEY (customername) REFERENCES Customer (customername),
	FOREIGN KEY (loannumber) REFERENCES Loan (loannumber)
);

DESC Borrower;
