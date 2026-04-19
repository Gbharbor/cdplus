/*
**  file: fork03.c
**
**  Paulo Shirley @ UAb
**  v2008/03/17
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
   pid_t pid;
   
   printf("\nExemplo de aplicacao 03 da funcao fork()\n");
   pid= fork();
   if ( pid==-1 ) {
      perror("Erro na funcao fork()");
      exit(1);
   }

   if ( pid ) {
      /* pid>0, codigo para o processo pai */
      printf("Codigo do Pai  :  PID=%5d  PPID=%5d\n", \
         (int) getpid(), (int) getppid());
   }
   else {
      /* pid=0, codigo para o processo filho */
      printf("Codigo do Filho:  PID=%5d  PPID=%5d\n", \
         (int) getpid(), (int) getppid());
      printf("Codigo do Filho:  Iniciado sleep(3)\n");
      sleep(3);
      printf("Codigo do Filho:  Terminado sleep(3)\n");
      printf("Codigo do Filho:  PID=%5d  PPID=%5d\n", \
         (int) getpid(), (int) getppid());
   }

   return 0;
}
