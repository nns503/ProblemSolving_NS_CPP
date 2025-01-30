select id, CASE
when SIZE_OF_COLONY <= 100 then 'LOW'
when SIZE_OF_COLONY > 100 AND SIZE_OF_COLONY <= 1000 then 'MEDIUM'
else 'HIGH'
end as SIZE
from ecoli_data
order by id asc