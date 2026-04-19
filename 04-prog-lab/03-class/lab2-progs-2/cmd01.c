/*
**  file: cmd01.c
**
**  Paulo Shirley @ UAb
**  v2009/03/12
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
   char cmd[]= "ps -f";
   /* char cmd[]= "ps -o pid,ppid,user,state,time,comm"; */

   printf("\nExecutando o comando \"%s\"\n",cmd);
   system(cmd);
   printf("*** Fim ***\n");
   return 0;
}
