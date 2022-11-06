/*M1*/
select Employees.employee_id  from Employees 
left join Salaries on Salaries.employee_id = Employees.employee_id 
where Employees.employee_id not in 
(
    select Employees.employee_id  from Employees 
    inner join Salaries on Salaries.employee_id = Employees.employee_id
)

union

select Salaries.employee_id  from Employees 
right join Salaries on Salaries.employee_id = Employees.employee_id 
where Salaries.employee_id not in 
(
    select Employees.employee_id  from Employees 
    inner join Salaries on Salaries.employee_id = Employees.employee_id
)
order by employee_id asc;

/*M2*/
select employee_id from Employees e 
where employee_id not in 
(
    select employee_id from Salaries
)

union

select employee_id from Salaries s
where employee_id not in 
(
    select employee_id from Employees
)
order by employee_id asc;