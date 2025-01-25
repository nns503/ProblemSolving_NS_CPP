select fh.flavor as FLAVOR
from first_half fh
join icecream_info ii
on fh.flavor = ii.flavor
where fh.total_order > 3000
and ii.ingredient_type like 'fruit_based'
order by fh.total_order desc;