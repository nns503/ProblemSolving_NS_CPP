-- 코드를 입력하세요
SELECT ai.animal_id, ai.name
from animal_ins ai
join animal_outs ao
on ai.animal_id = ao.animal_id
order by (ao.datetime - ai.datetime) desc
fetch first 2 row only;