SELECT a.animal_id, a.name
from animal_ins a
where lower(a.name) like '%el%'
and a.animal_type = 'Dog'
order by a.name