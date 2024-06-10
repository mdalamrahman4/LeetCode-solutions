# Write your MySQL query statement below
select e1.employee_id from employees as e1 where e1.salary<30000 and e1.manager_id is not null and e1.manager_id not in(
select e2.employee_id from employees as e2 ) order by e1.employee_id;