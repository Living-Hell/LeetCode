select d.name as Department, e.name as Employee, e.salary as Salary
from Department d, Employee e
where d.id = e.departmentId
and (e.departmentId, e.Salary) in 
(
    select departmentId, max(salary) 
    from Employee 
    group by departmentId
)
