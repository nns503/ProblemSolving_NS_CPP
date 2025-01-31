select d.id,
CASE
    WHEN d.rank_data <= 0.25 then 'CRITICAL'
    WHEN d.rank_data <= 0.5 then 'HIGH'
    WHEN d.rank_data <= 0.75 then 'MEDIUM'
    ELSE 'LOW'
END as colony_name
from (
    select id, PERCENT_RANK() OVER (order by size_of_colony desc) as rank_data
    from ecoli_data
) as d
order by id asc