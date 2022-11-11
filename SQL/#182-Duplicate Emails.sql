select email as Email 
from
(
    select email, count(email) as count 
    from Person 
    group by email
) s
where count>1;