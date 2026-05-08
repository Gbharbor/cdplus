/*
**  file: fork01.c
**
**  Paulo Shirley @ UAb
**  v2008/03/17
*/

#include <stdio.h>      /* printf(), perror() */
#include <stdlib.h>     /* exit() */
#include <unistd.h>     /* fork(), getpid(), getppid() */
#include <sys/types.h>  /* pid_t */

int main()
{
   /*
      pid_t é um tipo usado para guardar identificadores de processos.

      A variável pid vai guardar o valor retornado por fork():

      - no processo pai: recebe o PID do filho
      - no processo filho: recebe 0
      - em caso de erro: recebe -1
   */

   pid_t pid;
   
   printf("\nExemplo de aplicacao 01 da funcao fork()\n");

   /*
      getpid() retorna o PID do processo atual.

      Neste ponto ainda existe apenas um processo:
      o processo original, que será o pai.
   */

   printf("Processo pai tem PID=%5d\n", (int) getpid());

   /*
      fork() cria um novo processo.

      Depois desta chamada passam a existir dois processos:
      - o processo pai
      - o processo filho

      Ambos continuam a execução a partir da linha seguinte ao fork().
   */

   pid = fork();

   /*
      Se fork() retornar -1, ocorreu erro
      e o processo filho não foi criado.
   */

   if (pid == -1) {
      perror("Erro na funcao fork()");
      exit(1);
   }

   /*
      Se pid for diferente de 0, estamos no processo pai.

      No pai, fork() retorna o PID do processo filho.
   */

   if (pid) {
      /* pid > 0, código específico para o processo pai */

      /*
         getpid() retorna o PID do próprio processo pai.

         pid contém o PID do processo filho,
         porque foi esse o valor retornado por fork() no pai.
      */

      printf("Codigo do Pai:   Processo pai tem PID=%5d"
         " e o filho tem PID=%5d\n", (int) getpid(), (int) pid);
   }
   else {
      /*
         Se pid for 0, estamos no processo filho.

         No filho, fork() retorna sempre 0.
      */

      /* pid = 0, código específico para o processo filho */

      /*
         getppid() retorna o PID do processo pai.

         getpid() retorna o PID do próprio processo filho.
      */

      printf("Codigo do Filho: Processo pai tem PID=%5d"
         " e o filho tem PID=%5d\n", (int) getppid(), (int) getpid());
   }
   
   /*
      Este código está fora do if/else.

      Por isso, será executado pelos dois processos:
      - pai
      - filho

      Assim, a mensagem "*** Fim ***" aparece duas vezes.
   */

   printf("*** Fim ***\n");

   /*
      Cada processo termina a sua execução com sucesso.
   */

   return 0;
}