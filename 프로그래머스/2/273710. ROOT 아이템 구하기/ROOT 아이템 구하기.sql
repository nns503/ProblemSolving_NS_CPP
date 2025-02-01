select i.item_id as ITEM_ID, i.item_NAME as ITEM_NAME
from item_info i
join item_tree t on i.item_id = t.item_id
where t.parent_item_id is null
order by i.item_id asc