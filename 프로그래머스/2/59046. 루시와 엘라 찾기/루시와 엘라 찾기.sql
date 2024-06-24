-- 코드를 입력하세요
SELECT a.animal_id, a.name, a.sex_upon_intake
from animal_ins a
where a.name like 'Lucy'
OR a.name like 'Pickle'
OR a.name like 'Ella'
OR a.name like 'Rogan'
OR a.name like 'Sabrina'
OR a.name like 'Mitty'
order by a.animal_id