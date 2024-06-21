-- 코드를 입력하세요
SELECT a.animal_id, a.name
FROM ANIMAL_INS a
where a.intake_condition = 'Sick'
order by a.animal_id