select 
    h.history_id,
    truncate(case
    when datediff(end_date, start_date) + 1 >= 90
    then c.daily_fee * (100 - (
        select p.discount_rate
        from CAR_RENTAL_COMPANY_DISCOUNT_PLAN p
        where p.duration_type = '90일 이상'
        and p.car_type = c.car_type
    )) / 100
    when datediff(end_date, start_date) + 1 >= 30
    then c.daily_fee * (100 -  (
        select p.discount_rate
        from CAR_RENTAL_COMPANY_DISCOUNT_PLAN p
        where p.duration_type = '30일 이상'
        and p.car_type = c.car_type
    )) / 100
    when datediff(end_date, start_date) + 1 >= 7
    then c.daily_fee * (100 - (
        select p.discount_rate
        from CAR_RENTAL_COMPANY_DISCOUNT_PLAN p
        where p.duration_type = '7일 이상'
        and p.car_type = c.car_type
    )) / 100
    else c.daily_fee
    end, 0) * (datediff(end_date, start_date) + 1) as 'FEE'
from CAR_RENTAL_COMPANY_CAR c
join CAR_RENTAL_COMPANY_RENTAL_HISTORY h on c.car_id = h.car_id
where c.car_type = '트럭'
order by fee desc, history_id desc