select
    p.product_code as PRODUCT_CODE,
    (p.PRICE * sum(s.SALES_AMOUNT)) as SALES
from product p
join offline_sale s on p.product_id = s.product_id
group by p.product_code
order by SALES desc, PRODUCT_CODE asc