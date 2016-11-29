-- Filling Student table with values

INSERT INTO Student VALUES (2, 'Ram', 'EC', 'SR', 20);
INSERT INTO Student VALUES (3, 'Shyam', 'CS', 'SR', 20);
INSERT INTO Student VALUES (4, 'Raj', 'CS', 'JR', 18);
INSERT INTO Student VALUES (5, 'Tej', 'CS', 'SR', 22);
INSERT INTO Student VALUES (6, 'Chiru', 'EC', 'JR', 17);

SELECT * FROM Student;

-- Filling Faculty table with values

INSERT INTO Faculty VALUES (55, 'Prof. Harshith', 7);
INSERT INTO Faculty VALUES (66, 'Prof. Smit', 7);
INSERT INTO Faculty VALUES (77, 'Prof. Shankar', 8);
INSERT INTO Faculty VALUES (88, 'Prof. Daniel', 9);
INSERT INTO Faculty VALUES (99, 'Prof. Andrew', 9);

SELECT * FROM Faculty;

-- Filling Class table with values

INSERT INTO Class VALUES ('CS1', '12 HR', 'R128', 55);
INSERT INTO Class VALUES ('CS2', '11 HR', 'R138', 66);
INSERT INTO Class VALUES ('CS3', '12 HR', 'R148', 77);
INSERT INTO Class VALUES ('CS4', '11 HR', 'R158', 88);
INSERT INTO Class VALUES ('CS5', '12 HR', 'R168', 99);
INSERT INTO Class VALUES ('CS6', '1 HR', 'R138', 55);
INSERT INTO Class VALUES ('CS7', '2 HR', 'R148', 55);
INSERT INTO Class VALUES ('CS8', '3 HR', 'R158', 55);
INSERT INTO Class VALUES ('CS9', '4 HR', 'R168', 55);

SELECT * FROM Class;

-- Filling Enrolled table with values

INSERT INTO Enrolled VALUES (2, 'CS1');
INSERT INTO Enrolled VALUES (3, 'CS2');
INSERT INTO Enrolled VALUES (4, 'CS1');
INSERT INTO Enrolled VALUES (5, 'CS4');
INSERT INTO Enrolled VALUES (6, 'CS5');
INSERT INTO Enrolled VALUES (2, 'CS3');
INSERT INTO Enrolled VALUES (3, 'CS4');

SELECT * FROM Enrolled;
