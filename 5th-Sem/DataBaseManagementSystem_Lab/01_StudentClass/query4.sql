-- Find the names of faculty members who teach in every room in which some class is taught.

SELECT DISTINCT F.fname
FROM Faculty F
WHERE NOT EXISTS (
	SELECT *
	FROM Class C1
	WHERE C1.room NOT IN (
		SELECT C2.room
		FROM Class C2
		WHERE C2.fid = F.fid
	)
);
