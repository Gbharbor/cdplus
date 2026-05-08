/*
**  file: fork05.c
**
**  Paulo Shirley @ UAb
**  v2008/03/20
*/

#include <stdio.h>      /* printf(), perror() */
#include <stdlib.h>     /* exit() */
#include <unistd.h>     /* fork(), getpid(), getppid(), sleep() */
#include <sys/types.h>  /* pid_t */
#include <sys/wait.h>   /* wait() */

int main()
{
   /*
      pid  -> guarda o valor retornado por fork()

      No pai:
         pid = PID do filho

      No filho:
         pid = 0

      Em erro:
         pid = -1

      pidw -> guarda o PID do filho terminado,
              retornado por wait()

      status -> guarda o estado de terminação do filho
   */

   pid_t pid, pidw;
   int status;
   
   printf("\nExemplo de aplicacao 05 da funcao fork()\n");

   /*
      fork() cria um novo processo filho.

      Após esta chamada existem dois processos:
      - pai
      - filho
   */

   pid = fork();

   /*
      Se fork() retornar -1, ocorreu erro
      e o filho não foi criado.
   */

   if (pid == -1) {
      perror("Erro na funcao fork()");
      exit(1);
   }

   /*
      Se pid for diferente de 0, estamos no processo pai.

      O pai irá esperar explicitamente o filho terminar.
   */

   if (pid) {
      /* pid > 0, código para o processo pai */

      /*
         getpid()  -> PID do próprio processo pai
         getppid() -> PID do pai deste processo
      */

      printf("Codigo do Pai  :  PID=%5d  PPID=%5d\n",
         (int) getpid(), (int) getppid());

      /*
         wait() bloqueia o processo pai até que
         um dos seus filhos termine.

         Enquanto espera:
         - o pai fica bloqueado;
         - não desperdiça CPU;
         - o filho continua a executar normalmente.

         wait() retorna o PID do filho terminado.
      */

      printf("Codigo do Pai  :  Iniciado wait()\n");

      pidw = wait(&status);

      /*
         Quando wait() termina:
         - o filho já terminou;
         - o pai recolheu o estado do filho;
         - o processo filho é removido corretamente
           da tabela de processos.

         Isso evita processos Zombie.
      */

      printf("Codigo do Pai  :  Processo filho PID=%5d"
         " terminou!\n", (int) pidw);
   }
   else {
      /*
         Se pid for 0, estamos no processo filho.
      */

      /* pid = 0, código para o processo filho */

      /*
         O filho imprime os seus identificadores.
      */

      printf("Codigo do Filho:  PID=%5d  PPID=%5d\n",
         (int) getpid(), (int) getppid());

      /*
         sleep(8) suspende o filho durante 8 segundos.

         Durante esse tempo:
         - o pai fica bloqueado em wait()
         - o filho fica bloqueado em sleep()
      */

      printf("Codigo do Filho:  Iniciado sleep(8)\n");

      sleep(8);

      /*
         Após acordar, o filho continua normalmente.
      */

      printf("Codigo do Filho:  Terminado sleep(8)\n");

      /*
         O PPID continua igual porque o pai ainda existe.

         Diferente do exemplo fork03,
         aqui o pai NÃO termina antes do filho.
      */

      printf("Codigo do Filho:  PID=%5d  PPID=%5d\n",
         (int) getpid(), (int) getppid());
   }

   /*
      Neste programa:
      - o pai espera o filho terminar;
      - o filho nunca vira Zombie;
      - existe sincronização correta entre processos.

      Fluxo geral:

         fork()
            |
         +--+--+
         |     |
        Pai   Filho
         |       |
       wait()  sleep(8)
         |       |
         |   termina
         |
      wait() retorna
         |
      pai termina
   */

   return 0;
}