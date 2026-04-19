/*
**  file: fork04.c
**
**  Paulo Shirley @ UAb
**  v2008/03/20
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
   pid_t pid;
   
   printf("\nExemplo de aplicacao 04 da funcao fork()\n");
   pid= fork();
   if ( pid==-1 ) {
      perror("Erro na funcao fork()");
      exit(1);
   }

   if ( pid ) {
      /* pid>0, codigo para o processo pai */
      printf("Codigo do Pai  :  PID=%5d  PPID=%5d\n", \
         (int) getpid(), (int) getppid());
      printf("Codigo do Pai  :  Iniciado sleep(8)\n");
      sleep(8);
      printf("Codigo do Pai  :  Terminado sleep(8)\n");
   }
   else {
      /* pid=0, codigo para o processo filho */
      printf("Codigo do Filho:  PID=%5d  PPID=%5d\n", \
         (int) getpid(), (int) getppid());
   }

   return 0;
}
