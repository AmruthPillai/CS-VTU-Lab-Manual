-- For all aircraft with cruising range over 1000 Kms, find the name of the aircraft and the average salary of all pilots certified for this aircraft.

SELECT A.aname, AVG(E.salary) 
FROM Aircraft A, Certified C, Employees E
WHERE A.aid = C.aid AND
	E.eid = C.eid AND
	A.cruisingrange > 1000
GROUP BY A.aid, A.aname;
