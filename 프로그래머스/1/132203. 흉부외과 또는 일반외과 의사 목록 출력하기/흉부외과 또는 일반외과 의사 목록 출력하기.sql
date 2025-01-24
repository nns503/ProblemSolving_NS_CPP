select dr_name, dr_id, MCDP_CD, DATE_FORMAT(HIRE_YMD, '%Y-%m-%d')
from doctor
where mcdp_cd = 'CS' OR mcdp_cd = 'GS'
order by hire_ymd desc, dr_name asc;