/*M1*/
select 
case
    when id%2 =0 then id-1
    when id = (select max(id) from Seat) then id
    else id+1
end
as id, student from Seat
order by id asc;

/*M2*/
select 
if(id%2=0, 
    id-1, 
    if(id = (select max(id) from Seat),
        id,
        id+1))
as id, student from Seat
order by id asc;