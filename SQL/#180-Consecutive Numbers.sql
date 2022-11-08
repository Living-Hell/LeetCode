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