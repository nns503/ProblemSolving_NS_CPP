select ri.REST_ID, ri.REST_NAME, ri.FOOD_TYPE, ri.FAVORITES, ri.ADDRESS, round(avg(rv.review_score), 2) score
from rest_info ri
join rest_review rv
on ri.rest_id = rv.rest_id
where ri.address like '서울%'
group by ri.rest_id
order by score desc, ri.favorites desc