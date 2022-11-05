/*M1*/
delete from Person 
where id not in
(
    SELECT min_id
    from(
    select email, min(id) as min_id from Person group by email
    ) temp
);

/*M2*/
DELETE p from Person p, Person q where p.Id>q.Id AND q.Email=p.Email 