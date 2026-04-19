/*
**  file: fork05.c
**
**  Paulo Shirley @ UAb
**  v2008/03/20
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
   pid_t pid, pidw;
   int status;
   
   printf("\nExemplo de aplicacao 05 da funcao fork()\n");
   pid= fork();
   if ( pid==-1 ) {
      perror("Erro na funcao fork()");
      exit(1);
   }

   if ( pid ) {
      /* pid>0, codigo para o processo pai */
      printf("Codigo do Pai  :  PID=%5d  PPID=%5d\n", \
         (int) getpid(), (int) getppid());
      printf("Codigo do Pai  :  Iniciado wait()\n");
      pidw= wait(&status);
      printf("Codigo do Pai  :  Processo filho PID=%5d" \
         " terminou!\n", (int) pidw);
   }
   else {
      /* pid=0, codigo para o processo filho */
      printf("Codigo do Filho:  PID=%5d  PPID=%5d\n", \
         (int) getpid(), (int) getppid());
      printf("Codigo do Filho:  Iniciado sleep(8)\n");
      sleep(8);
      printf("Codigo do Filho:  Terminado sleep(8)\n");
      printf("Codigo do Filho:  PID=%5d  PPID=%5d\n", \
         (int) getpid(), (int) getppid());
   }

   return 0;
}
