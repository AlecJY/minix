#include <stdio.h>
#include <stdlib.h>
#include <minix/syslib.h>
#include <minix/drivers.h>

void testrt (void);
 
int main(int argc, char **argv)
{
    sef_startup();
 
    testrt();
    return EXIT_SUCCESS;
}

void testrt (void) {
  time_t recent, new;  /* times */
  int count;

  sys_setdl (120); /* let all other RT processes start up */
  sleep (1);   /* while we sleep */
  recent = time (NULL);
  count = 0;
  while (count < 100) {
    while ((new = time (NULL)) == recent) { /* still on the same second */
      sys_setdl (60);               /* check time again within one second*/
    }
    if (new == (recent + 1)) {  /* new second: did we skip any? */
      count++;                  /* no -- still working in realtime */
    } else {                    /* missed the deadline */
      sys_setdl (0);                /* no longer real time */
      printf ("missed deadline after %d seconds\n", count);
      break;
    }
    recent = new;
  }
  sys_setdl (0);                    /* no longer real time */
  printf ("successfully met %d successive deadlines\n", count);
}
