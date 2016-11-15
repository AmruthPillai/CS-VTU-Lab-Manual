-- Find the author of the book which has maximum sales.

SELECT A.name
FROM Author A
WHERE A.authorid IN (
	SELECT BC.authorid
	FROM Book_Catalog BC
	WHERE BC.bookid IN (
		SELECT OD.bookid
		FROM Order_Details OD
		WHERE OD.quantity = (
			SELECT MAX(OD.quantity)
			FROM Order_Details OD
		)
	)
);
