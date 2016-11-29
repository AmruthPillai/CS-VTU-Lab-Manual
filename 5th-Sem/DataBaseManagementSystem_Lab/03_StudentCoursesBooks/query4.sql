-- Produce a list of text books (include Course Number, Book ISBN, Book Title) in the alphabetical order for courses offered by the ‘CS’ department that use more than two books.

SELECT C.courseno, T.bookisbn, T.booktitle
FROM Course C, Book_Adoption BA, Text T
WHERE C.courseno = BA.courseno AND
	BA.bookisbn = T.bookisbn AND 
	C.dept = 'CS' AND
	EXISTS (
			SELECT *
			FROM Book_Adoption BA1
			WHERE BA1.courseno = C.courseno
			GROUP BY BA1.courseno
			HAVING COUNT(BA1.courseno) > 2
		) 
ORDER BY T.booktitle;
