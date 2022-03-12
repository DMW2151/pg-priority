create extension prio;

create table t_random AS 
    select 
        series as idx, 
        random() as val,
        md5(random()::text) AS hash
from generate_Series(1,500000) series;
