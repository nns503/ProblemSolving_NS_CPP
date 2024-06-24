-- 코드를 입력하세요
SELECT *
from (
    select ai.animal_id, ai.animal_type, ai.name
    from animal_ins ai
    where ai.sex_upon_intake like 'Intact%'
) a
where a.animal_id in (
    select ao.animal_id
    from animal_outs ao
    where ao.sex_upon_outcome not like 'Intact%'
) 