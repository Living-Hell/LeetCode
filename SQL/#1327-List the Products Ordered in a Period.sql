with t as(
    select product_id, sum(unit) as sum
    from Orders
    where month(order_date) = 02 and year(order_date) = 2020
    group by product_id
)
select p.product_name, t.sum as unit 
from Products p
left join t t
on p.product_id = t.product_id
where t.sum >= 100;