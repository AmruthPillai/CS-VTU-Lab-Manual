--  Demonstrate how you delete all account tuples at every branch located in a specific city.

DELETE FROM Account A
WHERE A.branchname IN (
	SELECT B.branchname
	FROM Branch B
	WHERE B.branchcity = 'BOMBAY'
);
