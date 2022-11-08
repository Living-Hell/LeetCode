/*M1*/
select distinct l.num as ConsecutiveNums 
from Logs l
where l.num = 
(
    select num from Logs where id = l.id +1
) 
and l.num = 
(
    select num from Logs where id = l.id +2
)

/*M2*/
select distinct l1.num as ConsecutiveNums 
from Logs l1, Logs l2, Logs l3
where l2.id - l1.id = 1 and l3.id - l1.id = 2
and l1.num = l2.num and l2.num = l3.num