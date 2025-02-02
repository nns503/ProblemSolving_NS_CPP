select 
    category,
    price as MAX_PRICE,
    product_name
from food_product p
where exists (
    select 1
    from food_product
    group by category
    having p.category = category
    and p.price = max(price)
)
and p.category in ('식용유', '국', '김치', '과자')
order by max_price desc