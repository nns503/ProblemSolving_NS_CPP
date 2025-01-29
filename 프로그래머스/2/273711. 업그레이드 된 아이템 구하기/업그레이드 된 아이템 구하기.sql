select i.item_id, i.item_name, i.rarity
from item_info i
where i.item_id in (
    select t.item_id
    from item_tree t
    join item_info ii
    on t.parent_item_id = ii.item_id
    where ii.rarity = 'rare'
)
order by i.item_id desc