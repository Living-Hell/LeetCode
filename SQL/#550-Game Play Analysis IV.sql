with t as(
    select player_id, min(event_date) as min_date
    from Activity
    group by player_id
)
select round(sum(if(datediff(a.event_date,t.min_date) = 1, 1, 0))/count(distinct a.player_id),2) as fraction
from Activity a
left join t t
on a.player_id = t.player_id;