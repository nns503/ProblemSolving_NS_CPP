select 
    i.item_id as item_id,
    i.item_name as item_name,
    i.rarity as rarity
from item_info i
left join item_tree t on i.item_id = t.parent_item_id
where parent_item_id is null
order by i.item_id desc