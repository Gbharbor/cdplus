/*
**  file: fork04.c
**
**  Paulo Shirley @ UAb
**  v2008/03/20
*/

#include <stdio.h>      /* printf(), perror() */
#include <stdlib.h>     /* exit() */
#include <unistd.h>     /* fork(), getpid(), getppid(), sleep() */
#include <sys/types.h>  /* pid_t */

int main()
{
   /*
      pid guarda o valor retornado por fork():

      - no processo pai: PID do filho
      - no processo filho: 0
      - em erro: -1
   */

   pid_t pid;
   
   printf("\nExemplo de aplicacao 04 da funcao fork()\n");

   /*
      fork() cria um processo filho.

      Depois desta chamada existem dois processos:
      - processo pai
      - processo filho
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

      Neste exemplo, o pai vai dormir durante 8 segundos.
      Isso faz com que o filho termine antes do pai.
   */

   if (pid) {
      /* pid > 0, código para o processo pai */

      /*
         getpid()  -> PID do próprio processo pai
         getppid() -> PID do processo pai deste processo
      */

      printf("Codigo do Pai  :  PID=%5d  PPID=%5d\n",
         (int) getpid(), (int) getppid());

      /*
         sleep(8) suspende o processo pai durante 8 segundos.

         Enquanto o pai está bloqueado, o processo filho termina.
      */

      printf("Codigo do Pai  :  Iniciado sleep(8)\n");

      sleep(8);

      /*
         Quando o pai acorda, o filho já terminou há algum tempo.
      */

      printf("Codigo do Pai  :  Terminado sleep(8)\n");
   }
   else {
      /*
         Se pid for 0, estamos no processo filho.

         O filho apenas imprime os seus identificadores
         e termina rapidamente.
      */

      /* pid = 0, código para o processo filho */

      /*
         getpid()  -> PID do próprio processo filho
         getppid() -> PID do processo pai
      */

      printf("Codigo do Filho:  PID=%5d  PPID=%5d\n",
         (int) getpid(), (int) getppid());

      /*
         Depois deste printf, o filho chega ao return 0
         e termina antes do pai.
      */
   }

   /*
      Neste programa, o filho termina antes do pai.

      Como o pai não chama wait(), o sistema operativo
      mantém temporariamente informação sobre o filho terminado
      na tabela de processos.

      Durante esse intervalo, o filho pode aparecer como Zombie (Z)
      no comando ps/pso.

      O estado Zombie significa:
      - o processo já terminou;
      - não está a executar;
      - não usa CPU;
      - mas ainda não foi recolhido pelo processo pai.
   */

   return 0;
}