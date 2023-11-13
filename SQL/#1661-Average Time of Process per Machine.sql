with st as(
select machine_id, process_id, sum(timestamp) as start, count(process_id) as cnt
from Activity 
where activity_type = 'start'
group by machine_id
),
endt as (
select machine_id, process_id, sum(timestamp) as end
from Activity 
where activity_type = 'end'
group by machine_id
)
select t1.machine_id, round((t1.end - t2.start)/t2.cnt,3) as processing_time
from endt t1
left join st t2
on t1.machine_id = t2.machine_id;