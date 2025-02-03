select
    e.emp_no,
    e.emp_name,
    grade.alp as grade,
    e.sal * grade.per as bonus
from hr_department d
join hr_employees e on d.dept_id = e.dept_id
join(
    select 
        emp_no,
        case 
        when avg(score) >= 96 then 'S' 
        when avg(score) >= 90 then 'A'
        when avg(score) >= 80 then 'B'
        else 'C'
    end as alp,
    case 
        when avg(score) >= 96 then 0.2
        when avg(score) >= 90 then 0.15
        when avg(score) >= 80 then 0.1
        else 0
    end as per
    from hr_grade
    group by emp_no
) as grade on grade.emp_no = e.emp_no
group by emp_no
order by emp_no