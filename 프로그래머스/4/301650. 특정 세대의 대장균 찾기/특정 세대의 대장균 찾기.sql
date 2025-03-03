with recursive ge as (
    select
        id,
        parent_id,
        1 as num
    from ecoli_data 
    where parent_id is null
    union all
    select
        e.id,
        e.parent_id,
        g.num + 1 as num
    from ecoli_data e
    join ge g on e.parent_id = g.id
)

select  
    id
from ge
where num = 3
order by id asc