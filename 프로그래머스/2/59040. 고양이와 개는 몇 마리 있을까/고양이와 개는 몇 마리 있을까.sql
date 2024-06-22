-- 코드를 입력하세요
SELECT a.animal_type, count(a.animal_type)
from animal_ins a
group by a.animal_type
order by a.animal_type