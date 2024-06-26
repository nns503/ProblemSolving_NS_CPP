-- 코드를 입력하세요
SELECT 
    HISTORY_ID, 
    CAR_ID, 
    TO_CHAR(START_DATE, 'YYYY-MM-DD') start_date, 
    TO_CHAR(END_DATE, 'YYYY-MM-DD') end_date,
CASE
when END_DATE - START_DATE >= 29 then '장기 대여'
when END_DATE - START_DATE < 29 then '단기 대여'
END RENT_TYPE
from car_rental_company_rental_history 
where start_date between to_date('2022-09-01', 'YYYY-MM-DD') 
AND to_date('2022-09-30', 'YYYY-MM-DD')
order by history_id desc