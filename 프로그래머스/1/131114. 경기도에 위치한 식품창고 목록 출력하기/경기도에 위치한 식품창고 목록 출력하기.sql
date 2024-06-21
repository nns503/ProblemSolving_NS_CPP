-- 코드를 입력하세요
SELECT fw.warehouse_id, fw.warehouse_name, fw.address, NVL(fw.freezer_yn, 'N')
from food_warehouse fw
where fw.address like '경기도%'
order by fw.warehouse_id;