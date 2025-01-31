select id, n.fish_name as FISH_NAME, mx.MAX_LENGTH as LENGTH
from fish_info i
join(
    select max(Length) as MAX_LENGTH, fish_type as MAX_TYPE
    from fish_info f
    group by f.fish_type
) as mx
on i.length = mx.MAX_LENGTH
and i.fish_type = mx.MAX_TYPE
join fish_name_info n
on i.fish_type = n.fish_type
order by id