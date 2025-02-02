select
    i.name as name,
    i.datetime as datetime
from animal_ins i
left join animal_outs o on i.animal_id = o.animal_id
where o.animal_id is null
order by i.datetime asc
limit 3