-- Demonstrate how you increase the price of books published by a specific publisher by 10%.

UPDATE  Catalog 
SET price = (1.1) * price
WHERE authorid = ( 
			SELECT publisherid
			FROM Publisher
			WHERE name = 'JOHN WILEY'
		)
;


--QUERY
SELECT bookid, title, price, price*1.1
FROM Catalog
WHERE publisherid IN (
			SELECT publisherid
			FROM Publisher
			WHERE name='JOHN WILEY'
		     )
;

--OUTPUT

--BOOKID 	TITLE			PRICE		PRICE*1.1
--2	    PRINCIPLES OF DBMS		400		440
