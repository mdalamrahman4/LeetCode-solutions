SELECT num 
FROM (
    SELECT num 
    FROM Mynumbers 
    GROUP BY num 
    HAVING COUNT(num) = 1 
    ORDER BY num DESC 
    LIMIT 1
) AS subquery
UNION ALL 
SELECT NULL
LIMIT 1;
