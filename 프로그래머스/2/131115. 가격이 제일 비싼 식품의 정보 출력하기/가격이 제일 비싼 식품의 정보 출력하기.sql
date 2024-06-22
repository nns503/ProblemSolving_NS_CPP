-- 코드를 입력하세요
SELECT *
from food_product f
where f.price = (
    select max(price)
    from food_product f
)