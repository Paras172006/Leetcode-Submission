# Write your MySQL query statement below
select w1.id
from Weather as w1
inner join Weather as w2
on subdate(w1.recordDate,1) = w2.recordDate
and w1.temperature > w2.temperature