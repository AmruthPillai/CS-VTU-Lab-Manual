-- Demonstrate how you increase the price of books published by a specific publisher by 10%.

SELECT BC.bookid, BC.title, BC.price, price*1.1
FROM Book_Catalog BC
WHERE BC.publisherid IN (
	SELECT P.publisherid
	FROM Publisher P
	WHERE P.name='JOHN WILEY'
);
