with t as(
    select managerId, count(managerId) as count from employee
    group by managerId
)
select e.name from Employee e
left join t t
on e.id = t.managerId
where t.count>= 5;