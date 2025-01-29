SELECT i.item_id, i.item_name, i.rarity
FROM item_info i
JOIN item_tree t ON i.item_id = t.item_id
JOIN item_info parent ON t.parent_item_id = parent.item_id
WHERE parent.rarity = 'rare'
ORDER BY i.item_id DESC;
