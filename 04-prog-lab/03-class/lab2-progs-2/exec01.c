/*
**  file: exec01.c
**
**  Paulo Shirley @ UAb
**  v2008/03/24
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
   
   printf("\nExemplo de aplicacao 01 das funcoes fork()+exec()\n");
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
   }
   else {
      /* pid=0, codigo para o processo filho */
      printf("Codigo do Filho:  Substituir imagem do processo " \
         "pela do comando ls e executar!\n");
      execl("/bin/ls","ls","-al",NULL);
      printf("Se esta mensagem aparecer ocorreu um erro!");
   }
   
   printf("Codigo do Pai  :  Comando ls -al executado!\n");

   return 0;
}
