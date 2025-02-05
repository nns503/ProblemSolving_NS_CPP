select
    history_id,
    car_id,
    date_format(start_date, '%Y-%m-%d'),
    date_format(end_date, '%Y-%m-%d'),
    if(datediff(end_date, start_date) + 1 >= 30, '장기 대여', '단기 대여') as RENT_TYPE
from CAR_RENTAL_COMPANY_RENTAL_HISTORY h
where start_date >= '2022-09-01'
and start_date <= '2022-09-30'
order by history_id desc
