select
    s.sum_score as score,
    e.emp_no,
    e.emp_name,
    e.position,
    e.email
from hr_department d
join hr_employees e on d.dept_id = e.dept_id
join (
    select 
        emp_no,
        sum(score) as sum_score
    from hr_grade
    group by emp_no
) as s on s.emp_no = e.emp_no
order by score desc
limit 1