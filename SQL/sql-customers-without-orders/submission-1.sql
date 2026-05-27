-- Write your query below
-- SELECT c.name FROM customers c 
-- WHERE c.id NOT IN (
--     SELECT customer_id FROM orders
-- )

-- left join customers <- orders
-- keep all the customer id and match orders id over
-- is not match it's going to be NULL
SELECT c.name FROM customers c
LEFT JOIN orders o
ON o.customer_id = c.id
WHERE o.customer_id IS NULL;