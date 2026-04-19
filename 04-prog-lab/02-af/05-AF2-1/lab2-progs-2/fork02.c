/*
**  file: fork02.c
**
**  Paulo Shirley @ UAb
**  v2008/03/17
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define NITER  2

int main()
{
   pid_t pid;
   int i;
   
   printf("\nExemplo de aplicacao 02 da funcao fork()\n");
   printf("Processo pai inicial tem PID=%5d\n", (int) getpid());
   for(i=1; i<=NITER; i++) {
      pid= fork();
      if ( pid==-1 ) {
         perror("Erro na funcao fork()");
         exit(1);
      }
      if ( pid ) {
         /* pid>0, codigo para o processo pai */
         printf("Codigo do Pai  (i=%2d):  PID=%5d  PPID=%5d\n", \
            i, (int) getpid(), (int) getppid());
      }
      else {
         /* pid=0, codigo para o processo filho */
         printf("Codigo do Filho(i=%2d):  PID=%5d  PPID=%5d\n", \
            i, (int) getpid(), (int) getppid());
      }
   }
   return 0;
}
