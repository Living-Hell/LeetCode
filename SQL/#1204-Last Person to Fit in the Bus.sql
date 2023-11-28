with t as(
    select person_name, sum(weight)over(order by turn) as pref_sum
    from Queue
)
select person_name
from t
where pref_sum <= 1000
order by pref_sum desc
limit 1;