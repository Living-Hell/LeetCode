delete from Person 
where id not in
(
    SELECT min_id
    from(
    select email, min(id) as min_id from Person group by email
    ) temp
);