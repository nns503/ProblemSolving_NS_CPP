
select 
    s.flavor
from
    (
    select 
        j.flavor as flavor,
        j.total_order + ifnull(f.total_order, 0) as sum_order
    from july j
    left join first_half f on f.shipment_id = j.shipment_id 
    order by j.shipment_id
    ) as s
group by s.flavor
order by sum(s.sum_order) desc
limit 3