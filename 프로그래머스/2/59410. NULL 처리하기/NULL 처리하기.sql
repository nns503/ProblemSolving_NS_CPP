-- 코드를 입력하세요
SELECT a.animal_type, NVL(a.name, 'No name'), a.sex_upon_intake
from animal_ins a
order by animal_id