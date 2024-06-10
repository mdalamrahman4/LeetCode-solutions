/*select m1.machine_id,round(avg(m2.timestamp-m1.timestamp),3) as processing_time 
from activity m1 join activity m2 on m1.machine_id=m2.machine_id and m1.process_id=m2.process_id and m1.activity_type='start' and m2.activity_type='end' 
group by machine_id;*/
select m1.machine_id,round(
(select avg(timestamp) from activity m2 where m2.activity_type='end' and m1.machine_id=m2.machine_id)-
    (select avg(timestamp) from activity m2 where m2.activity_type='start' and m2.machine_id=m1.machine_id),3) as processing_time 
    from activity m1 group by m1.machine_id;