-- Using cross join and left join
with t1 as(
    select s.student_id, s.student_name, s1.subject_name 
    from Students s
    cross join Subjects s1
),
t2 as(
    select student_id, subject_name, count(subject_name) as attended_exams 
    from Examinations 
    group by student_id,subject_name
)
select t1.student_id, t1.student_name, t1.subject_name, ifnull(t2.attended_exams,0) as attended_exams
from t1 t1
left join t2 t2
on t1.student_id = t2.student_id and t1.subject_name = t2.subject_name
order by s.student_id, s1.subject_name;