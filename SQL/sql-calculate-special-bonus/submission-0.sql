-- Write your query below

-- NOT LIKE 'M%' <- not start with M, % means anything
--
-- CASE
--  WHEN condition1 THEN val1
--  WHEN condition2 THEN val2
--  ELSE default_val
-- END

SELECT employee_id, 
CASE
    WHEN employee_id % 2 = 1 AND name NOT LIKE 'M%' THEN salary
    ELSE 0
END AS bonus
FROM employees
ORDER BY employee_id;