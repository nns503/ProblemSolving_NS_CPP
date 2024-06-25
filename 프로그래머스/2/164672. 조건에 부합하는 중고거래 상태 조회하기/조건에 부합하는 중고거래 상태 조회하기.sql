-- 코드를 입력하세요
SELECT u.board_id, u.writer_id, u.title, u.price, 
case u.status
when 'SALE' then '판매중'
when 'RESERVED' then '예약중'
when 'DONE' then '거래완료'
end
from used_goods_board u
where u.created_date = to_date('2022-10-05', 'YYYY-MM-DD')
order by u.board_id desc