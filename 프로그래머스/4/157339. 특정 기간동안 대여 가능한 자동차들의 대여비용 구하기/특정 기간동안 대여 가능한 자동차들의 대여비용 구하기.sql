select distinct
    c.car_id, 
    c.car_type,
    TRUNCATE((c.daily_fee * ((100 - p.discount_rate) / 100)) * 30, 0) as FEE
from car_rental_company_car c
join car_rental_company_rental_history h on c.car_id = h.car_id
join CAR_RENTAL_COMPANY_DISCOUNT_PLAN p on c.car_type = p.car_type
where c.car_type in ('세단', 'SUV')
and p.duration_type = '30일 이상'
and c.car_id not in (
    select ch.car_id
    from car_rental_company_rental_history ch
    where ch.end_date >= '2022-11-01'
    and ch.start_date <= '2022-11-30'
)
and TRUNCATE(c.daily_fee * (100 - p.discount_rate) / 100 * 30, 0) >= 500000
and TRUNCATE(c.daily_fee * (100 - p.discount_rate) / 100 * 30, 0) < 2000000
order by fee desc, car_type asc, car_id asc