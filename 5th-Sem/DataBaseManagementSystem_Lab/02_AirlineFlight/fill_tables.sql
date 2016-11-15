-- Filling Aircraft table with values

INSERT INTO Aircraft VALUES (1, 'Airbus', 2000);
INSERT INTO Aircraft VALUES (2, 'Boeing', 700);
INSERT INTO Aircraft VALUES (3, 'Jet', 550);
INSERT INTO Aircraft VALUES (4, 'Dreamliner', 5000);
INSERT INTO Aircraft VALUES (5, 'Boeing', 4500);
INSERT INTO Aircraft VALUES (6, 'Airbus', 2200);

SELECT * FROM Aircraft;

-- Filling Employees table with values

INSERT INTO Employees VALUES (162, 'Andrew', 50000);
INSERT INTO Employees VALUES (183, 'Laeddis', 60000);
INSERT INTO Employees VALUES (192, 'Rachel', 70000);
INSERT INTO Employees VALUES (204, 'Solando', 82000);
INSERT INTO Employees VALUES (300, 'Tony', 5000);

SELECT * FROM Employees;


-- Filling Certified table with values

INSERT INTO Certified VALUES (162, 2);
INSERT INTO Certified VALUES (162, 4);
INSERT INTO Certified VALUES (162, 5);
INSERT INTO Certified VALUES (162, 6);
INSERT INTO Certified VALUES (183, 1);
INSERT INTO Certified VALUES (183, 3);
INSERT INTO Certified VALUES (183, 5);
INSERT INTO Certified VALUES (192, 2);
INSERT INTO Certified VALUES (192, 3);
INSERT INTO Certified VALUES (192, 5);
INSERT INTO Certified VALUES (192, 6);
INSERT INTO Certified VALUES (204, 6);
INSERT INTO Certified VALUES (204, 1);
INSERT INTO Certified VALUES (204, 3);
INSERT INTO Certified VALUES (300, 3);

SELECT * FROM Certified;

-- Filling Flights table with values

INSERT INTO Flights VALUES (1, 'Bengaluru', 'New Delhi', 500, '30-JUL-16', '30-JUL-16', 5000);
INSERT INTO Flights VALUES (2, 'Bengaluru', 'Chennai', 300, '30-JUL-16', '30-JUL-16', 3000);
INSERT INTO Flights VALUES (3, 'Trivandrum', 'New Delhi', 800, '30-JUL-16', '30-JUL-16', 6000);
INSERT INTO Flights VALUES (4, 'Bengaluru', 'Frankfurt', 10000, '30-JUL-16', '30-JUL-16', 50000);
INSERT INTO Flights VALUES (5, 'Kolkata', 'New Delhi', 2400, '30-JUL-16', '30-JUL-16', 9000);
INSERT INTO Flights VALUES (6, 'Bengaluru', 'Frankfurt', 8000, '30-JUL-16', '30-JUL-16', 40000);

SELECT * FROM Flights;
