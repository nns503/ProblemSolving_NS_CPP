select 
    e.dept_id,
    d.dept_name_en,
    round(avg(e.sal), 0) as AVG_SAL
from hr_department d
join HR_EMPLOYEES e on d.dept_id = e.dept_id
group by e.dept_id
order by avg_sal desc