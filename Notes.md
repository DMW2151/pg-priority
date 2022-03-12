# Build && Usage Notes

```bash
# Build Container
docker build . -t dmw2151/pg

# Run
docker run -ti \
    --name pg-prio \
    -v $(pwd)/benchmarks:/benchmarks \
    -e POSTGRES_PASSWORD=pgprio \
    dmw2151/pg

# Install Extension
docker exec -ti pg-prio psql \
    -U postgres \
    -d postgres \
    -f /benchmarks/benchmarks-init.sql

# Run Benchmarks
docker exec -ti pg-prio pgbench \
    -c 10 \
    -j 4 \
    -U postgres \
    -d postgres \
    -f /benchmarks/baseline.sql \
    -f /benchmarks/low-priority.sql
```
