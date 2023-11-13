select customer_id, count(customer_id) 
as count_no_trans 
from Visits 
where visit_id not in (
    select Visits.visit_id 
    from Visits right join Transactions 
    on Visits.visit_id = Transactions.visit_id
    group by Visits.visit_id
)
group by customer_id;

-- M2
select customer_id, count(customer_id) as count_no_trans  from Visits
where visit_id not in (select visit_id from Transactions)
group by customer_id;