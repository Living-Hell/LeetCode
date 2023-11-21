select t.class 
from (select class, count(student) as count from Courses group by class) t
where t.class >= 5;