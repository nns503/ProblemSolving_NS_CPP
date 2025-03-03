with max_member as (
    select 
        member_id
    from rest_review
    group by member_id
    order by count(member_id) desc
    limit 1
    
)
select 
    m.member_name,
    r.review_text,
    date_format(r.review_date, "%Y-%m-%d") as review_date
from rest_review r
join member_profile m
on r.member_id = m.member_id
where m.member_id = (
    select *
    from max_member
)
order by r.review_date asc, r.review_text asc