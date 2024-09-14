CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
declare m int;
set m=n-1;
  RETURN (
      # Write your MySQL query statement below.
       select salary from employee e1 where m=(select count(distinct(salary)) from
        employee e2 where e2.salary>e1.salary) order by salary limit 1
  );
END