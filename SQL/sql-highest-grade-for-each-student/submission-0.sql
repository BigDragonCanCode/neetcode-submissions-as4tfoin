-- Write your query below
-- SELECT student_id, exam_id, MAX(score) as score FROM exam_results
-- GROUP BY student_id, exam_id
-- ORDER BY student_id;

-- SELECT * FROM exam_results e
-- WHERE score = (
--     SELECT MAX(score) FROM exam_results
--     WHERE student_id = e.student_id
-- )
-- AND
-- exam_id = (
--     SELECT min(exam_id) FROM exam_results
--     WHERE student_id = e.student_id AND score = e.score
-- );

SELECT student_id, exam_id, score FROM (
    SELECT *,
    ROW_NUMBER() OVER (
        PARTITION BY student_id
        ORDER BY score DESC, exam_id ASC
    ) as row_num
    FROM exam_results
) x
WHERE row_num = 1;

