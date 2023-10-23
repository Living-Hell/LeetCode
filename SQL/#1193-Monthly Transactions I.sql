with t1 as(
    SELECT DATE_FORMAT(trans_date , '%Y-%m') AS month, country, count(*) as trans_count, sum(amount) as trans_total_amount
    from Transactions 
    group by month, country
),
t2 as (
    select count(state) as approved_count, DATE_FORMAT(trans_date , '%Y-%m') AS month, sum(amount) as approved_total_amount, country
    from Transactions 
    where state = 'approved'
    group by month, country
)

select t1.month, t1.country, t1.trans_count, ifnull(t2.approved_count,0) as approved_count , t1.trans_total_amount,
    ifnull(t2.approved_total_amount,0) as approved_total_amount 
from t1 t1 
left join t2 t2
on t1.month = t2.month and t1.country = t2.country;
