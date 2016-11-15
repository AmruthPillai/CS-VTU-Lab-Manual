-- List any department that has all its adopted books published by a specific publisher.

SELECT C.dept, T.booktitle, T.publisher 
FROM Course C, Text T, Book_Adoption BA 
WHERE C.courseno = BA.courseno AND 
	T.bookisbn = BA.bookisbn AND
	T.publisher = 'PEARSON' AND
	T.publisher = ALL (
		SELECT T1.publisher 
		FROM Course C1, Book_Adoption BA1, Text T1 
		WHERE BA1.bookisbn = T1.bookisbn AND
			BA1.courseno = C1.courseno AND 
			C.dept = C1.dept
	);
