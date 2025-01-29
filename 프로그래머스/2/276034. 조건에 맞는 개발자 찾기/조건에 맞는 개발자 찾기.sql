select d.id, d.email, d.first_name, d.last_name
from developers d
where d.skill_code & (
    select sum(code)
    from skillcodes
    where name in ('C#', 'Python') 
)
order by d.id asc