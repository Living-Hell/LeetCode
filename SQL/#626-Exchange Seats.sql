select 
case
    when id%2 =0 then id-1
    when id = (select max(id) from Seat) then id
    else id+1
end
as id, student from Seat
order by id asc;