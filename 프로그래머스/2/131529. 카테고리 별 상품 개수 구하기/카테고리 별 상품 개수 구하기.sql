-- 코드를 입력하세요
SELECT substr(p.product_code, 1, 2) as category, count(p.product_code) as products
from product p
group by substr(p.product_code, 1, 2)
order by category asc