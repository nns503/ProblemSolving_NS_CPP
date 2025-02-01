select round(avg(i.l), 2) as average_length
from (
    select ifnull(length, 10) as l
    from fish_info
) i;
