-- Find all the customers who have at least two accounts at the Main branch.

SELECT *
FROM Customer C
WHERE EXISTS (
	SELECT D.customername, COUNT(D.customername)
	FROM Depositor D, Account A
	WHERE D.accno = A.accno AND
		C.customername = D.customername AND
		A.branchname = 'RESIDENCY ROAD'
	GROUP BY D.customername
	HAVING COUNT(D.customername) >= 2
);
