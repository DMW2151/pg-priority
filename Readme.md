
# Resource Control Manager

A small PostgreSQL extension that can be added to PostgreSQL to manage query priority for the active connection. Under the hood, the functions, `deprioritize_cpu` and `deprioritize_io` makes syscalls to
[setpriority(2)](https://linux.die.net/man/2/setpriority) and [ioprio_set(2)](https://linux.die.net/man/2/ioprio_set) respectively.

## References

- [PostgreSQL Documentation - C-Language Functions](https://www.postgresql.org/docs/13/xfunc-c.html)
- [Postgres C Extensions](https://www.percona.com/blog/2019/04/05/writing-postgresql-extensions-is-fun-c-language/)
- [Postgres C Extensions for Dumb-Dumbs](https://www.percona.com/blog/2019/07/31/postgresql-simple-c-extension-development-for-a-novice-user/)