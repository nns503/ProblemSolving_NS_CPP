select 
    i.animal_id as animal_id,
    i.animal_type as animal_type,
    i.name as name
from animal_ins i
join animal_outs o on i.animal_id = o.animal_id
where i.sex_upon_intake like 'Intact%'
AND o.sex_upon_outcome not like 'Intact%'
order by animal_id asc