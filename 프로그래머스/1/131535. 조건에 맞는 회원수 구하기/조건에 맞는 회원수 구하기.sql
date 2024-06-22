-- 코드를 입력하세요
SELECT count(*) 
from user_info u
where '2021' = TO_CHAR(u.joined, 'YYYY') 
AND u.age >= 20 
AND u.age <= 29