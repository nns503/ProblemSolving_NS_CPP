with recursive family AS(
    select 1 as gen, id, parent_id
    from ecoli_data
    where parent_id is null
    
    union all
    
    select f.gen + 1, e.id, e.parent_id 
    from ecoli_data e
    join family f on f.id = e.parent_id 
)

select 
    count(f.gen) as count, 
    f.gen as generation
from family f
where f.id not in (
    select distinct parent_id
    from family
    where parent_id is not null
)
group by f.gen
order by generation asc