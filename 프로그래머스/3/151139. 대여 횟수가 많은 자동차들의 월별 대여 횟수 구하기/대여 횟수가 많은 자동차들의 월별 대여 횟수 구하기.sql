select 
    month(start_date) as month,
    h.car_id,
    count(h.car_id) as records
from CAR_RENTAL_COMPANY_RENTAL_HISTORY h
join (
    select car_id, count(car_id) as count_id
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where start_date between '2022-08-01' and '2022-10-31'
    group by car_id
) as all_sum on h.car_id = all_sum.car_id
where start_date between '2022-08-01' and '2022-10-31'
and all_sum.count_id >= 5
group by h.car_id, month(start_date)
order by month asc, h.car_id desc