select 
    left(product_code, 2) as CATEGORY,
    count(*) as PRODUCTS
from product 
group by left(product_code, 2) 
order by category asc