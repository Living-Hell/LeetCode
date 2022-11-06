/*M1*/
select id, 
if
(
    p_id is null, "Root", if
    (
        id in (select p_id from Tree), "Inner", "Leaf"
    )
)
as type
from Tree
order by id asc;

/*M2*/
select id, 
case
   when p_id is null then 'Root' 
   when id  in (select p_id from Tree) then 'Inner'
   else 'Leaf'
end
as type
from Tree
order by id asc;