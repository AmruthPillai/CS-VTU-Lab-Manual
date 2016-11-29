-- Filling Author table with values

INSERT INTO Author VALUES (1, 'NAVATHE', 'ARLINGTON', 'USA');
INSERT INTO Author VALUES (2, 'RAGHU RAMAKRISHNAN', 'CALIFORNIA', 'USA');
INSERT INTO Author VALUES (3, 'DHAMDHERE', 'MUMBAI', 'INDIA');
INSERT INTO Author VALUES (4, 'BJARNE', 'NEW JERSY', 'USA');
INSERT INTO Author VALUES (5, 'TANENBAUM', 'AMSTERDAM','NETHERLAND');

SELECT * FROM Author;

-- Filling Publisher table with values

INSERT INTO Publisher VALUES (1, 'JOHN WILEY', 'NEW YORK', 'USA');
INSERT INTO Publisher VALUES (2, 'PEARSON', 'BANGALORE', 'INDIA');
INSERT INTO Publisher VALUES (3, 'O REILLY', 'NEW JERSY', 'USA');
INSERT INTO Publisher VALUES (4, 'TMH', 'CALCUTTA', 'INDIA');
INSERT INTO Publisher VALUES (5, 'JOHN WILEY', 'NEW DELHI', 'INDIA');

SELECT * FROM Publisher;

-- Filling Book_Category table with values

INSERT INTO Book_Category VALUES (1, 'DATABASE MANAGEMENT');
INSERT INTO Book_Category VALUES (2, 'OPERATING SYSTEMS');
INSERT INTO Book_Category VALUES (3, 'C++');
INSERT INTO Book_Category VALUES (4, 'COMPUTER NETWORKS');
INSERT INTO Book_Category VALUES (5, 'C');

SELECT * FROM Book_Category;

-- Filling Book_Catalog table with values

INSERT INTO Book_Catalog VALUES (1, 'FUNDAMENTALS OF DBMS', 1, 2, 1, 2004, 500);
INSERT INTO Book_Catalog VALUES (2, 'PRINCIPLES OF DBMS', 2, 1, 1, 2004, 400);
INSERT INTO Book_Catalog VALUES (3, 'OPERATING SYSTEMS', 3, 4, 2, 2004, 200);
INSERT INTO Book_Catalog VALUES (4, 'C++ BIBLE', 4, 5, 3, 2003, 500);
INSERT INTO Book_Catalog VALUES (5, 'COMPUTER NETWORKS', 5, 3, 4, 2002, 250);
INSERT INTO Book_Catalog VALUES (6, 'FUNDAMENTALS OF C', 1, 2, 5, 2004, 700);
INSERT INTO Book_Catalog VALUES (7, 'OPERATING SYSTEMS 2', 3, 2, 2, 2001, 600);

SELECT * FROM Book_Catalog;

-- Filling Order_Details table with values

INSERT INTO Order_Details VALUES (1, 1, 1);
INSERT INTO Order_Details VALUES (2, 2, 1);
INSERT INTO Order_Details VALUES (3, 3, 1);
INSERT INTO Order_Details VALUES (4, 4, 1);
INSERT INTO Order_Details VALUES (5, 5, 1);
INSERT INTO Order_Details VALUES (6, 6, 7);
INSERT INTO Order_Details VALUES (7, 7, 9);

SELECT * FROM Order_Details;
