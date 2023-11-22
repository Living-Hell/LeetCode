with t as(
    select reports_to, count(reports_to) as reports_count , round(avg(age)) as average_age 
    from Employees
    group by reports_to
)
select e.employee_id, e.name, t.reports_count, t.average_age
from Employees e
inner join t t
on e.employee_id = t.reports_to
order by e.employee_id asc;