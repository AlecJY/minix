#include "kernel/system.h"

int do_setdl(struct proc * caller, message *m_ptr) {
    caller->deadline = get_realtime() + m_ptr->m_m2.m2l1;
    return(OK);
}