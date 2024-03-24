select name
from
(
    SELECT name
    from animal_ins 
    order by animal_ins.datetime
)
where rownum = 1;