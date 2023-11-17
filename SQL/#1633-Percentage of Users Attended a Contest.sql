select r.contest_id, round(count(r.user_id)/(select count(*) from users u)*100,2) as percentage 
from Register r
group by r.contest_id
order by percentage desc, r.contest_id asc;