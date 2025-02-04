select 
    concat(quarter(DIFFERENTIATION_DATE), 'Q') as quarter,
    count(*) as ECOLI_COUNT
from ecoli_data
group by concat(quarter(DIFFERENTIATION_DATE), 'Q')
order by quarter asc