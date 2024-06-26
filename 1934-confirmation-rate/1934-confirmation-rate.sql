# Write your MySQL query statement below
select 
    s.user_id,
    Round(Avg(If(c.action='confirmed',1,0)),2) as confirmation_rate 
from 
    signups as s left join Confirmations as c
on 
    s.user_id = c.user_id
group by 
    user_id;