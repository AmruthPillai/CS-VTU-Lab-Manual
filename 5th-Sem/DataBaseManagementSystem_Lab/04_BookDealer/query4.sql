-- Find the author of the book which has maximum sales.

SELECT A.name
FROM Author A, Book_Catalog BC, Order_Details OD
WHERE A.authorid = BC.authorid AND
	BC.bookid = OD.bookid AND
	OD.quantity = (
		SELECT MAX(OD.quantity)
		FROM Order_Details OD
	);
