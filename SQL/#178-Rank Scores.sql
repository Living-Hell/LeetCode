/*M1*/
select s1.score, count(distinct s2.score) as "rank"
from Scores s1, Scores s2
where s2.score >= s1.score
group by s1.id
order by s1.score desc;

/*M2*/
select s1.score, 
(select count(distinct score) from Scores s2 where s2.score>=s1.score)
as "rank"
from Scores s1
order by s1.score desc;