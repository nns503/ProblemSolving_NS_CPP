select 
    a.author_id,
    a.author_name,
    b.category,
    sum(bs.sales * b.price) as total_sales
from book_sales bs
join book b on bs.book_id = b.book_id
join author a on a.author_id = b.author_id
where bs.sales_date between '2022-01-01' and '2022-01-31'
group by a.author_id, a.author_name, b.category
order by author_id asc, category desc