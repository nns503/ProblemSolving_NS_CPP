-- 코드를 입력하세요
SELECT d.DR_NAME, d.DR_ID, d.MCDP_CD, TO_CHAR(d.HIRE_YMD, 'YYYY-MM-DD') HIRE_YMD
from doctor d
where d.MCDP_CD = 'CS' 
OR d.MCDP_CD = 'GS'
order by d.hire_ymd desc, d.dr_name asc