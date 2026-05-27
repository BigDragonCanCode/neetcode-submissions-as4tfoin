-- Write your query below
-- if not appeared it will be NULL, replace with 0
SELECT name, COALESCE(SUM(distance),0) as travelled_distance FROM users u
LEFT JOIN rides r -- user with no rides still shows up as 0
ON r.user_id = u.id
GROUP BY u.id, name
ORDER BY travelled_distance DESC, name;