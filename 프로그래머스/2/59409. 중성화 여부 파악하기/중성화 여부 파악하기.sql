-- 코드를 입력하세요
SELECT 
    ai.animal_id,
    ai.name, 
    CASE
        when ai.sex_upon_intake like 'Neutered%'
        OR ai.sex_upon_intake like 'Spayed%'
        then 'O'
    else 'X'
    end
from animal_ins ai
order by ai.animal_id