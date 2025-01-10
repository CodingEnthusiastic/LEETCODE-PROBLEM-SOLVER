# Write your MySQL query statement below
SELECT * FROM Cinema WHERE id%2 NOT IN(0) AND description NOT LIKE 'boring' ORDER BY rating DESC;
