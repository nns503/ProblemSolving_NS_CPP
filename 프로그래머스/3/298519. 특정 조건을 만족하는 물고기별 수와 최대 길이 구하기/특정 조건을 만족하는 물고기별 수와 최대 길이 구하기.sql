select
    count(*) as fish_count,
    max(i.length) as max_length,
    i.fish_type
from (
    select 
        id,
        fish_type,
        ifnull(length, 10) as length
    from fish_info
) as i
group by i.fish_type
having avg(i.length) >= 33
order by i.fish_type