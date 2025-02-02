select
    o.animal_id as animal_id,
    o.name as name
from animal_ins i
right join animal_outs o on i.animal_id = o.animal_id
where i.animal_id is null
order by animal_id