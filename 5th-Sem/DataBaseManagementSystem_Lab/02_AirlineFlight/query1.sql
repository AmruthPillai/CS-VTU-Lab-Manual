-- Find the names of Aircraft such that all pilots certified to operate them have salaries more than Rs. 80,000.

SELECT DISTINCT A.aname
FROM Aircraft A
WHERE A.aid IN (
	SELECT C.aid
	FROM Certified C, Employees E
	WHERE C.eid = E.eid AND
		E.salary > 80000
);
