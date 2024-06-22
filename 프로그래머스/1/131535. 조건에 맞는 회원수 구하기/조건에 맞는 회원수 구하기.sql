-- 코드를 입력하세요
SELECT count(*) 
from user_info u
where '2021' = TO_CHAR(u.joined, 'YYYY') 
AND u.age between 20 and 29