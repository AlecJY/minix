#include "syslib.h"

int sys_setdl(long deadline) {
    message m;
    int r;

    m.m_m2.m2l1 = deadline;
    r = _kernel_call(SYS_SETDL, &m);
    return 0;
}

int setdl(long deadline) {
    message m;
    m.m_m2.m2l1 = deadline;
    return(_syscall(PM_PROC_NR, PM_SETDL, &m));
}