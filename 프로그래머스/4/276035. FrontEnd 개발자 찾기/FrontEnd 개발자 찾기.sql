select distinct d.id as id, d.email as email, d.first_name as first_name,
d.last_name as last_name
from skillcodes s
join developers d 
on d.skill_code & (
    select sum(code)
    from skillcodes
    where category = 'Front End'
) > 0
order by d.id asc;