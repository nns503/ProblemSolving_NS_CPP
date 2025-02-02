select
    year(o.sales_date) YEAR,
    month(o.sales_date) MONTH,
    count(distinct o.user_id) PURCHASED_USERS,
    round(count(distinct o.user_id) / 
          (
              select count(*)
              from user_info i
              where year(i.joined) = '2021'
          )
          , 1) PUCHASED_RATIO
from user_info u
join online_sale o on u.user_id = o.user_id
where year(u.joined) = '2021'
group by year, month
order by year, month