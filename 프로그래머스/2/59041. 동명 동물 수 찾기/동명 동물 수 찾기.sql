-- 코드를 입력하세요
SELECT a.name, count(a.name)
from animal_ins a
group by a.name
having count(a.name) >= 2
order by a.name