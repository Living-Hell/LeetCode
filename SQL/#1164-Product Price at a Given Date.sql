with t as(
    select product_id, max(change_date) as date
    from Products
    where change_date <= '2019-08-16'
    group by product_id
)

select p.product_id, ifnull(p.new_price,10) as price
from Products p
right join t t
on (t.product_id = p.product_id and p.change_date = t.date)
group by p.product_id

union

select product_id, 10
from Products
group by product_id
having min(change_date) > '2019-08-16';