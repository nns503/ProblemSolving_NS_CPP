select e.id
from ecoli_data e
left join ecoli_data p1 on e.parent_id = p1.id
left join ecoli_data p2 on p1.parent_id = p2.id
where p2.parent_id is null
and p1.parent_id is not null
order by e.id