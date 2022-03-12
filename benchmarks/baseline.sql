select deprioritize_io(0);
select deprioritize_cpu(0);

select LEFT(hash, 2) AS prefix,
    percentile_cont(random()) within group (order by t.val) AS p_rand
from t_random t
group by 1;