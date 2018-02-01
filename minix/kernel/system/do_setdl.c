#include "kernel/system.h"

int do_setdl(struct proc * caller, message *m_ptr) {
    printf("Deadline: %ld\n", m_ptr->m_m2.m2l1);
    return(OK);
}