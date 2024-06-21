-- 코드를 입력하세요
SELECT count(name)
from (
    select a.name
    from animal_ins a
    group by a.name
);