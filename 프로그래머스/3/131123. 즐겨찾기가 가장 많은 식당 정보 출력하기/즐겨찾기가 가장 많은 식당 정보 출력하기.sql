# select *
# from rest_info
# order by favorites desc
select
    i.food_type,
    i.rest_id,
    i.rest_name,
    i.favorites
from rest_info i
join (
    select r.food_type , max(r.favorites) as max_fav
    from rest_info r
    group by food_type
) as max_info
on max_info.food_type = i.food_type
and max_info.max_fav = i.favorites
order by food_type desc