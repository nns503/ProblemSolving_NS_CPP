select factory_id, factory_name, address
from food_factory f
where address like '강원도%'
order by f.factory_id asc