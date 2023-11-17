select p.project_id, round(avg(e.experience_years),2) as average_years 
from employee e
right join Project p
on p.employee_id = e.employee_id
group by p.project_id;