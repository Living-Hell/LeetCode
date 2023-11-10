-- M1
-- Using inner join
select p.product_name, s.year, s.price
from Product p
inner join Sales s
on p.product_id = s.product_id;