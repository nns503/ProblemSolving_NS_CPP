-- 코드를 입력하세요
SELECT ai.name, ai.datetime
from animal_ins ai
where not exists (
    select 1
    from animal_outs ao
    where ai.animal_id = ao.animal_id
)
order by ai.datetime
FETCH FIRST 3 ROWS ONLY;