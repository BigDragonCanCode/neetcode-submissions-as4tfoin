-- Write your query below
-- SELECT * from customers c
-- WHERE c.customer_id IN (
--     SELECT customer_id FROM orders WHERE product_name = 'A'
-- )
-- AND c.customer_id IN (
--     SELECT customer_id FROM orders WHERE product_name = 'B'
-- )
-- AND c.customer_id NOT IN (
--     SELECT customer_id FROM orders WHERE product_name = 'C'
-- )
-- ORDER BY customer_name;


SELECT c.customer_id, c.customer_name FROM customers c
JOIN orders o
ON o.customer_id = c.customer_id
GROUP BY c.customer_id, c.customer_name -- every selected column needs appear in group by
HAVING
    SUM(CASE WHEN product_name='A' THEN 1 ELSE 0 END) > 0 AND
    SUM(CASE WHEN product_name='B' THEN 1 ELSE 0 END) > 0 AND
    SUM(CASE WHEN product_name='C' THEN 1 ELSE 0 END) = 0
ORDER BY customer_name;
