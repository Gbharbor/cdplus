/*
**  file: exec01.c
**
**  Paulo Shirley @ UAb
**  v2008/03/24
*/

#include <stdio.h>      /* printf(), perror() */
#include <stdlib.h>     /* exit() */
#include <unistd.h>     /* fork(), execl(), getpid(), getppid() */
#include <sys/types.h>  /* pid_t */
#include <sys/wait.h>   /* wait() */

int main()
{
   /*
      pid  -> guarda o valor retornado por fork()
              No pai: recebe o PID do filho
              No filho: recebe 0
              Em erro: recebe -1

      pidw -> guarda o PID do processo filho que terminou,
              retornado pela função wait()

      status -> guarda o estado de terminação do processo filho
   */

   pid_t pid, pidw;
   int status;
   
   printf("\nExemplo de aplicacao 01 das funcoes fork()+exec()\n");

   /*
      fork() cria um novo processo.

      Depois desta chamada passam a existir dois processos:
      - processo pai
      - processo filho

      Ambos continuam a executar o código a partir deste ponto.
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

      Isto acontece porque, no processo pai, fork()
      retorna o PID do processo filho criado.
   */

   if (pid) {
      /* pid > 0, código executado pelo processo pai */

      /*
         getpid()  -> retorna o PID do processo atual, neste caso o pai
         getppid() -> retorna o PID do pai deste processo
      */

      printf("Codigo do Pai  :  PID=%5d  PPID=%5d\n",
         (int) getpid(), (int) getppid());

      /*
         O pai chama wait() para esperar o processo filho terminar.

         Isto evita que o filho fique em estado zombie.
         Enquanto espera, o pai fica bloqueado, mas não desperdiça CPU.
      */

      printf("Codigo do Pai  :  Iniciado wait()\n");

      pidw = wait(&status);

      /*
         Neste programa, pidw não é impresso,
         mas ele recebe o PID do filho que terminou.

         status recebe informação sobre como o filho terminou.
      */
   }
   else {
      /*
         Se pid for 0, estamos no processo filho.

         Isto acontece porque, no processo filho,
         fork() retorna sempre 0.
      */

      /* pid = 0, código executado pelo processo filho */

      printf("Codigo do Filho:  Substituir imagem do processo "
         "pela do comando ls e executar!\n");

      /*
         execl() substitui a imagem do processo filho
         pela imagem de outro programa.

         Neste caso, o filho deixa de executar este código C
         e passa a executar o comando:

            ls -al

         Argumentos:
         "/bin/ls" -> caminho absoluto do programa a executar
         "ls"      -> nome passado como argv[0]
         "-al"     -> argumento do comando ls
         NULL      -> marca o fim da lista de argumentos

         Importante:
         Se execl() funcionar corretamente, ela NÃO retorna.
         O processo filho passa a ser o programa ls.
      */

      execl("/bin/ls", "ls", "-al", NULL);

      /*
         Esta mensagem só aparece se execl() falhar.

         Se execl() tiver sucesso, o código abaixo nunca será executado,
         porque a imagem do processo já foi substituída pelo comando ls.
      */

      printf("Se esta mensagem aparecer ocorreu um erro!");
   }
   
   /*
      Esta linha será executada pelo processo pai.

      O filho normalmente não chega aqui, porque foi substituído
      pelo comando ls através de execl().
   */

   printf("Codigo do Pai  :  Comando ls -al executado!\n");

   /*
      Termina o processo com sucesso.
   */

   return 0;
}