select max(salary) as SecondHighestSalary 
from 
(
    select salary from Employee 
    where salary <
    (
        select max(salary) 
        from Employee
    )
) 
as s;