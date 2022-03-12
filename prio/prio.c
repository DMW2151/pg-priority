#include <sys/time.h>
#include <sys/resource.h>
#include <sys/syscall.h>     /* Definition of SYS_* constants */

#include <unistd.h>

#include "postgres.h"
#include "fmgr.h"

#define IOPRIO_CLASS_SHIFT  (13)
#define IOPRIO_PRIO_VALUE(class, data)  (((class) << IOPRIO_CLASS_SHIFT) | data)

enum {
    IOPRIO_WHO_PROCESS = 1,
    IOPRIO_WHO_PGRP,
    IOPRIO_WHO_USER,
};

enum {
    IOPRIO_CLASS_NONE,
    IOPRIO_CLASS_RT,
    IOPRIO_CLASS_BE,
    IOPRIO_CLASS_IDLE,
};

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(deprioritize_cpu);
PG_FUNCTION_INFO_V1(deprioritize_io);

Datum
deprioritize_cpu(PG_FUNCTION_ARGS)
{
    int32 prio = PG_GETARG_INT32(0);
    int result = setpriority(PRIO_PROCESS, 0, prio);

    if (result == 0) {
        PG_RETURN_BOOL(1);
    } else {
        PG_RETURN_BOOL(0);
    }
}

Datum
deprioritize_io(PG_FUNCTION_ARGS)
{
    int32 ioprio = PG_GETARG_INT32(0);

    // glibc provides no wrappers for these system calls,
    // necessitating the use of syscall(2).
    int result = syscall(
        SYS_ioprio_set, IOPRIO_WHO_PROCESS, 0,
        IOPRIO_PRIO_VALUE(IOPRIO_CLASS_BE, ioprio)
    );

    if (result == 0) {
        PG_RETURN_BOOL(1);
    } else {
        PG_RETURN_BOOL(0);
    }
}
