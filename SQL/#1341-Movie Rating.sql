with t1 as (
    select user_id, count(user_id) as cnt
    from MovieRating
    group by user_id
),
t2 as (
    select movie_id, avg(rating) as rating
    from MovieRating
    where month(created_at) = 02 and year(created_at) = 2020
    group by movie_id
)
(
    select u.name as results
    from Users u
    left join t1 t
    on t.user_id = u.user_id
    where t.cnt = (select max(cnt) from t1)
    order by name asc
    limit 1
)
union all
(
    select m.title as results
    from Movies m
    left join t2 t
    on t.movie_id = m.movie_id
    where t.rating = (select max(rating) from t2)
    order by title asc
    limit 1
)