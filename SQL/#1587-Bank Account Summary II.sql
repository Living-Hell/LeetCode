/*M1*/
select u.name, s.balance 
from Users u
left join 
(
    select account, sum(amount) as balance 
    from Transactions
    group by account
) s
on u.account = s.account
where s.balance>10000;

/*M2*/
select u.name, sum(t.amount) as balance 
from Users u left join Transactions t 
on u.account = t.account
group by t.account
having sum(t.amount) > 10000