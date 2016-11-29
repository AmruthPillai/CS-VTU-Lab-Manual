-- Find all the customers who have an account at all the branches located in a specific city.

SELECT D.customername
FROM Branch B, Account A, Depositor D
WHERE B.branchname = A.branchname AND
	A.accno = D.accno AND
	B.branchcity = 'DELHI'
GROUP BY D.customername
HAVING COUNT(DISTINCT B.branchname) = (
	SELECT COUNT(branchname)
	FROM Branch
	WHERE branchcity = 'DELHI'
);
