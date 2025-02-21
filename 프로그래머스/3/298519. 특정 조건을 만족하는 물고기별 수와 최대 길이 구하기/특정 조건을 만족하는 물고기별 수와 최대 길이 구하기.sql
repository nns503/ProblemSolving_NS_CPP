with info as (
    select
        id,
        fish_type,
        coalesce(length, 10) as length
    from fish_info
)

select
    count(id) as fish_count,
    max(length) as MAX_LENGTH,
    fish_type
from fish_info
where fish_type in (
    select 
        fish_type
    from info
    group by fish_type
    having avg(length) >= 33
)
group by fish_type
order by fish_type asc
