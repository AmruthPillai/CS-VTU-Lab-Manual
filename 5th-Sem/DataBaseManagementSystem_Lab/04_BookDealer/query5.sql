-- Demonstrate how you increase the price of books published by a specific publisher by 10%.

SELECT BC.bookid, BC.title, BC.price, price*1.1
FROM Book_Catalog BC, Publisher P
WHERE BC.publisherid = P.publisherid AND
	P.name='JOHN WILEY';
