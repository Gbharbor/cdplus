/*
**  file: fork03.c
**
**  Paulo Shirley @ UAb
**  v2008/03/17
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
   
   printf("\nExemplo de aplicacao 03 da funcao fork()\n");

   /*
      fork() cria um novo processo.

      Depois desta chamada existem dois processos:
      - pai
      - filho
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

      O pai apenas imprime os seus identificadores
      e termina rapidamente.
   */

   if (pid) {
      /* pid > 0, código para o processo pai */

      /*
         getpid()  -> PID do processo pai
         getppid() -> PID do processo que criou este pai
      */

      printf("Codigo do Pai  :  PID=%5d  PPID=%5d\n",
         (int) getpid(), (int) getppid());
   }
   else {
      /*
         Se pid for 0, estamos no processo filho.

         O filho vai imprimir os seus identificadores,
         dormir durante 3 segundos e depois imprimir novamente.
      */

      /* pid = 0, código para o processo filho */

      /*
         Antes do sleep(), o PPID normalmente ainda é
         o PID do processo pai original.
      */

      printf("Codigo do Filho:  PID=%5d  PPID=%5d\n",
         (int) getpid(), (int) getppid());

      /*
         sleep(3) suspende o processo filho durante 3 segundos.

         Enquanto o filho está suspenso, o pai pode terminar
         a sua execução antes dele.
      */

      printf("Codigo do Filho:  Iniciado sleep(3)\n");

      sleep(3);

      /*
         Quando o filho acorda, o pai original provavelmente
         já terminou.

         Nesse caso, o filho torna-se um processo órfão
         e o sistema operativo atribui-lhe um novo processo pai.

         Normalmente esse novo pai é o processo init/systemd,
         mas em sistemas modernos pode não ter PID 1.
      */

      printf("Codigo do Filho:  Terminado sleep(3)\n");

      /*
         Aqui o PPID pode ser diferente do PPID mostrado antes
         do sleep(), porque o pai original pode já ter terminado.
      */

      printf("Codigo do Filho:  PID=%5d  PPID=%5d\n",
         (int) getpid(), (int) getppid());
   }

   /*
      O processo pai termina logo após imprimir a sua mensagem.

      O processo filho termina apenas depois do sleep(3).
   */

   return 0;
}