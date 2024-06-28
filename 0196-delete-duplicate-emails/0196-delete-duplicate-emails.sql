# Write your MySQL query statement below
delete t1 from person t1 join person t2 
where
    t1.email=t2.email and t1.id>t2.id;