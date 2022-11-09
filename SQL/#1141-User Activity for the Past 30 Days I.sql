select activity_date as day, count(distinct user_id) as active_users
from Activity
where DATEDIFF('2019-07-27', activity_date) < 30
AND activity_date <= '2019-07-27'
group by activity_date;