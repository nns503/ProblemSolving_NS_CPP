select
    route,
    concat(round(sum(d_between_dist), 1), 'km') as total_distance,
    concat(round(avg(d_between_dist), 2), 'km') as AVERAGE_DISTANCE
from subway_distance d
group by d.route
order by sum(d_between_dist) desc