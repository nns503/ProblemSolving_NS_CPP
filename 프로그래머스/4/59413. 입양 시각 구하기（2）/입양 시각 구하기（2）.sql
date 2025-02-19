with recursive num as (
    select 0 as n
    union all
    select n + 1
    from num
    where n <= 22
)

select 
    n as hour,
    coalesce(h.count, 0) as count
from num
left join 
( select
    hour(datetime) as hour,
    count(animal_id) as count
from animal_outs
group by hour(datetime) 
order by hour
) as h
on h.hour = num.n
order by hour