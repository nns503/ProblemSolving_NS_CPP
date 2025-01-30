select d.id, if(parent.child_count is NULL, 0, parent.child_count) child_count
from ecoli_data d
left join ( 
    select parent_id, count(*) as child_count
    from ecoli_data
    group by parent_id
) as parent
on d.id = parent.parent_id 
order by d.id