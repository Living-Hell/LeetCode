# Write your MySQL query statement below
select e.name, b.bonus
from employee e
left join bonus b
on e.empId = b.empId
where e.empId not in (select empId from Bonus where bonus >= 1000);