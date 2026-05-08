/*
**  file: fork02.c
**
**  Paulo Shirley @ UAb
**  v2008/03/17
*/

#include <stdio.h>      /* printf(), perror() */
#include <stdlib.h>     /* exit() */
#include <unistd.h>     /* fork(), getpid(), getppid() */
#include <sys/types.h>  /* pid_t */

/*
   Número de iterações do ciclo.

   Cada iteração executa um novo fork(),
   duplicando todos os processos existentes naquele momento.

   Crescimento do número de processos:

   NITER = 1 -> 2 processos
   NITER = 2 -> 4 processos
   NITER = 3 -> 8 processos

   Fórmula:
      2^NITER
*/

#define NITER  2

int main()
{
   /*
      pid guarda o valor retornado por fork():

      - no pai: PID do filho
      - no filho: 0
      - erro: -1

      i controla as iterações do ciclo.
   */

   pid_t pid;
   int i;
   
   printf("\nExemplo de aplicacao 02 da funcao fork()\n");

   /*
      Antes do primeiro fork() existe apenas um processo:
      o processo original (pai inicial).
   */

   printf("Processo pai inicial tem PID=%5d\n", (int) getpid());

   /*
      O ciclo executa NITER vezes.

      IMPORTANTE:
      Após cada fork(), o número de processos duplica.

      Como todos os processos continuam o ciclo,
      cada processo também executa os próximos fork().
   */

   for(i = 1; i <= NITER; i++) {

      /*
         Cria um novo processo.

         Todos os processos que chegam aqui serão duplicados.
      */

      pid = fork();

      /*
         Se ocorrer erro, fork() retorna -1.
      */

      if (pid == -1) {
         perror("Erro na funcao fork()");
         exit(1);
      }

      /*
         Código executado pelo processo pai.

         No pai:
            pid contém o PID do processo filho criado.
      */

      if (pid) {

         /* pid > 0, código do processo pai */

         /*
            getpid()  -> PID do próprio processo
            getppid() -> PID do processo pai deste processo
         */

         printf("Codigo do Pai  (i=%2d):  PID=%5d  PPID=%5d\n",
            i, (int) getpid(), (int) getppid());
      }
      else {

         /*
            Código executado pelo processo filho.

            No filho:
               pid == 0
         */

         /* pid = 0, código do processo filho */

         printf("Codigo do Filho(i=%2d):  PID=%5d  PPID=%5d\n",
            i, (int) getpid(), (int) getppid());
      }

      /*
         Após terminar esta iteração,
         TODOS os processos continuam para a próxima iteração.

         Exemplo com NITER = 2:

         Iteração 1:
            1 processo -> 2 processos

         Iteração 2:
            2 processos -> 4 processos

         Estrutura aproximada:

                  Pai Inicial
                  /        \
              Filho1     Filho2
               /             \
          Filho3          Filho4

         Na prática, a ordem de execução pode variar,
         porque os processos executam concorrentemente.
      */
   }

   /*
      Todos os processos terminam aqui.

      Como existem múltiplos processos,
      o programa termina várias vezes simultaneamente.
   */

   return 0;
}