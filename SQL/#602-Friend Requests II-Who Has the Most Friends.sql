with t as(
    select requester_id as id
    from RequestAccepted 
    union all
    select accepter_id as id
    from RequestAccepted 
)
select id, count(id) as num
from t
group by id
order by num desc
limit 1;