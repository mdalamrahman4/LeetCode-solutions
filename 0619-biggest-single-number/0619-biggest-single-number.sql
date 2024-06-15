# Write your MySQL query statement below
select num from (select (num) from Mynumbers group by num having count(num)=1 order by num desc limit 1) as subquery union all select null limit 1;