-- 코드를 입력하세요
SELECT to_number(to_char(a.datetime, 'HH24')) as HOUR, count(*) as COUNT
from animal_outs a
group by to_char(a.datetime, 'HH24')
having to_char(a.datetime, 'HH24') >= 9 
AND to_char(a.datetime, 'HH24') <= 19
order by to_char(a.datetime, 'HH24')