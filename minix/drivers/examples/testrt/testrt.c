#include <stdio.h>
#include <stdlib.h>
#include <minix/syslib.h>

int main(int argc, char **argv) {
    sef_startup();

    sys_setdl(120);
    return EXIT_SUCCESS;
}