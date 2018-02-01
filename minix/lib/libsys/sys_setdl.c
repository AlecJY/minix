#include "syslib.h"

int sys_setdl(long deadline) {
    message m;
    int r;

    m.m_m2.m2l1 = deadline;
    r = _kernel_call(SYS_SETDL, &m);
    return 0;
}