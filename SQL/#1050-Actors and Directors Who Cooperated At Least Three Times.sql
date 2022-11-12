select actor_id, director_id 
from
(   
    select distinct actor_id, director_id, count(timestamp) as count
    from ActorDirector 
    group by actor_id, director_id
) s
where count>=3;