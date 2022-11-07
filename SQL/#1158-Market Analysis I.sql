/*M1*/
select Users.user_id as buyer_id, Users.join_date,
case 
    when s.orders_in_2019 is null then 0
    else s.orders_in_2019
end
as orders_in_2019
from Users 
left join
    (select buyer_id, count(buyer_id) as orders_in_2019 
    from Orders 
    where order_date >= '2019-01-01' and order_date <= '2019-12-31' 
    group by buyer_id) s
on s.buyer_id = Users.user_id; 