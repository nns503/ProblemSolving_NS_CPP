select 
    o.product_id, 
    p.product_name,
    p.price * sum(o.amount) as total_sales
from food_product p  
join food_order o on p.product_id = o.product_id
where year(o.produce_date) = '2022'
and month(o.produce_date) = '5'
group by o.product_id, p.product_name
order by total_sales desc, product_id asc