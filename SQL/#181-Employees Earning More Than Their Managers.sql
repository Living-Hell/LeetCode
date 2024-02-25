with t as(
    select e.name as manName, e.salary as manSalary, m.name as name, m.salary as salary
    from Employee e, Employee m
    where m.managerId = e.id
)
select name as Employee
from t
where salary > manSalary;