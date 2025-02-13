select member_id, member_name, gender, date_format(Date_of_birth, '%Y-%m-%d') date_of_birth
from member_profile 
where month(date_of_birth) = 3
and gender = 'W'
and TLNO is not null
order by member_id asc