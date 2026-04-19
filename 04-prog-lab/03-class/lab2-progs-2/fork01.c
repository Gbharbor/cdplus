/*
**  file: fork01.c
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
   
   printf("\nExemplo de aplicacao 01 da funcao fork()\n");
   printf("Processo pai tem PID=%5d\n", (int) getpid());
   pid= fork();
   if ( pid==-1 ) {
      perror("Erro na funcao fork()");
      exit(1);
   }
   if ( pid ) {
      /* pid>0, codigo especifico para o processo pai */
      printf("Codigo do Pai:   Processo pai tem PID=%5d" \
         " e o filho tem PID=%5d\n", (int) getpid(), (int) pid);
   }
   else {
      /* pid=0, codigo especifico para o processo filho */
      printf("Codigo do Filho: Processo pai tem PID=%5d" \
         " e o filho tem PID=%5d\n", (int) getppid(), (int) getpid());
   }
   
   /* pid irrelevante, codigo para ambos os processos, pai e filho */
   printf("*** Fim ***\n");
   return 0;
}
