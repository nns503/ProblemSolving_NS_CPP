-- 코드를 입력하세요
SELECT a.animal_id, a.name, to_char(a.datetime, 'YYYY-MM-DD') 날짜
from animal_ins a
order by a.animal_id