select concat('/home/grep/src/', f.board_id, '/', f.FILE_ID, f.FILE_NAME, f.FILE_EXT) as FILE_PATH
from used_goods_file f
join (
    select board_id
    from used_goods_board b
    order by views desc
    limit 1
) as vb on vb.board_id = f.board_id
order by f.file_id desc