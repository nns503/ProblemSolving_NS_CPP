with user_count as (select count(*)
from user_info
where year(joined) = '2021')

select
    year(s.sales_date),
    month(s.sales_date),
    count(distinct i.user_id) as purchased_users,
    round(count(distinct i.user_id) / (select * from user_count), 1) as puchased_ratio
from user_info i
join online_sale s 
on s.user_id = i.user_id
where year(i.joined) = '2021'
group by year(s.sales_date), month(s.sales_date)
order by year(s.sales_date) asc, month(s.sales_date) asc