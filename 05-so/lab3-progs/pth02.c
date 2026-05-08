/*
**  file: pth02.c
**
**  Objetivo:
**  Somar os primeiros N números naturais:
**
**      1 + 2 + 3 + ... + N
**
**  Diferença em relação ao pth01.c:
**
**  - pth01.c:
**      Só existe a tarefa principal.
**
**  - pth02.c:
**      A tarefa principal cria uma nova tarefa/thread.
**      A nova tarefa é quem faz a soma.
**
**  Este programa é bi-tarefa:
**  - tarefa principal: executa a função main();
**  - sub-tarefa: executa a função tarefa().
**
**  A sub-tarefa é criada como "detached".
**
**  Isso significa que:
**  - a tarefa principal não usa pthread_join();
**  - a tarefa principal não espera diretamente pelo resultado;
**  - quando a sub-tarefa termina, os seus recursos são libertados automaticamente.
*/

#include <pthread.h>   /* Biblioteca POSIX Threads */
#include <stdio.h>     /* printf(), perror() */
#include <stdlib.h>    /* exit() */
#include <sys/types.h> /* tipos como pid_t */
#include <unistd.h>    /* getpid(), sleep() */

/*
   Quantidade de números naturais a somar.

   O programa vai calcular:

      1 + 2 + 3 + ... + 1081080
*/
#define N 1081080


/*
   Protótipo da função soma().

   Esta função recebe um vetor e a quantidade de elementos
   a somar, devolvendo a soma total.
*/
double soma(double x[], int n);


/*
   Protótipo da função tarefa().

   Esta função será executada pela sub-tarefa criada com
   pthread_create().

   Obrigatoriamente, uma função usada por pthread_create()
   deve ter este formato:

      void *funcao(void *arg)

   Ou seja:
   - recebe um ponteiro genérico void *;
   - devolve um ponteiro genérico void *.
*/
void *tarefa(void *arg);


/*
   Variáveis globais.

   v[N]:
   - guarda os números naturais de 1 até N.

   S:
   - guarda a soma total.

   Como são globais, tanto a tarefa principal como a sub-tarefa
   conseguem aceder a estas variáveis.
*/
double v[N], S;


int main()
{
   int i, r;

   /*
      trfid:
      variável que guarda o identificador da thread criada.

      É como se fosse o "nome técnico" da sub-tarefa dentro
      do programa.
   */
   pthread_t trfid;

   /*
      trfatr:
      variável que guarda atributos da thread.

      Aqui será usada para definir que a sub-tarefa será
      criada no estado "detached".
   */
   pthread_attr_t trfatr;

   /*
      getpid() devolve o PID do processo.

      Importante:
      threads pertencem ao mesmo processo.
      Por isso, a tarefa principal e a sub-tarefa normalmente
      mostram o mesmo PID.
   */
   printf("\nA iniciar a tarefa principal: PID=%d\n", (int) getpid());

   /*
      Preenche o vetor v[] com os números naturais.

      v[0] = 1
      v[1] = 2
      v[2] = 3
      ...
      v[N - 1] = N
   */
   for(i = 0; i < N; i++)
      v[i] = i + 1;

   /*
      Inicializa a variável de atributos da thread com valores
      padrão.

      Antes de alterar qualquer atributo, é necessário chamar
      pthread_attr_init().
   */
   pthread_attr_init(&trfatr);

   /*
      Altera o estado da thread para "detached".

      PTHREAD_CREATE_DETACHED significa:
      - a thread fica desacoplada da tarefa principal;
      - a tarefa principal não precisa fazer pthread_join();
      - os recursos da thread são libertados automaticamente
        quando ela termina.
   */
   pthread_attr_setdetachstate(&trfatr, PTHREAD_CREATE_DETACHED);

   /*
      Cria uma nova thread.

      Argumentos:

      &trfid:
      - endereço da variável onde será guardado o ID da thread.

      &trfatr:
      - atributos da thread;
      - neste caso, indica que ela será detached.

      tarefa:
      - função que a nova thread vai executar.

      (void *) NULL:
      - argumento enviado para a função tarefa();
      - aqui não estamos a enviar nenhum dado, por isso usamos NULL.

      A partir deste ponto, passam a existir duas tarefas:
      - a tarefa principal continua na função main();
      - a sub-tarefa começa a executar a função tarefa().
   */
   r = pthread_create(&trfid, &trfatr, tarefa, (void *) NULL);

   /*
      pthread_create() devolve:
      - 0 se criou a thread com sucesso;
      - outro valor se ocorreu erro.

      Se r for diferente de 0, houve erro.
   */
   if(r) {
      perror("Erro na criacao da tarefa!");
      exit(1);
   }

   /*
      Como a sub-tarefa foi criada como detached, a tarefa principal
      não pode usar pthread_join() para esperar por ela.

      Por isso, este exemplo usa sleep(4).

      sleep(4) faz a tarefa principal ficar bloqueada durante
      4 segundos.

      A ideia é dar tempo para a sub-tarefa:
      - iniciar;
      - calcular a soma;
      - imprimir o resultado;
      - terminar.

      Se este sleep() fosse removido ou colocado como sleep(0),
      a função main() poderia terminar antes da sub-tarefa.
      Quando a main() termina, o processo inteiro acaba,
      e a sub-tarefa pode ser encerrada antes de imprimir a soma.
   */
   sleep(4);

   /*
      Depois dos 4 segundos, a tarefa principal termina.
   */
   printf("A terminar a tarefa principal.\n\n");

   return 0;
}


/*
   Função executada pela sub-tarefa.

   Esta função começa a correr quando pthread_create()
   cria a nova thread.

   O parâmetro arg existe porque pthread_create() exige que
   a função da thread receba um void *.

   Neste programa, arg não é usado.
*/
void *tarefa(void *arg)
{
   /*
      Imprime o PID do processo.

      Como threads pertencem ao mesmo processo, este PID deverá
      ser igual ao PID mostrado pela tarefa principal.
   */
   printf("A iniciar a sub-tarefa: PID=%d\n", (int) getpid());

   /*
      A sub-tarefa calcula a soma de todos os elementos do vetor v[].

      Como v[] é global, a sub-tarefa consegue aceder ao vetor
      preenchido anteriormente pela tarefa principal.
   */
   S = soma(v, N);

   /*
      Imprime o resultado da soma.

      %.0lf imprime o número sem casas decimais.
   */
   printf(" Soma= %.0lf\n", S);

   /*
      Mensagem indicando que a sub-tarefa chegou ao fim.
   */
   printf("A terminar a sub-tarefa.\n");

   /*
      Como a função da thread tem retorno void *,
      devolvemos NULL.

      Neste exemplo, a tarefa principal não recolhe este retorno,
      porque a sub-tarefa é detached.
   */
   return (void *) NULL;
}


/*
   Função soma()

   Soma os n primeiros elementos do vetor x[].
*/
double soma(double x[], int n)
{
   int i;
   double s = 0;

   /*
      Percorre o vetor da posição 0 até n - 1.

      A cada repetição, acumula o valor de x[i] em s.
   */
   for(i = 0; i < n; i++)
      s += x[i];

   /*
      Devolve a soma calculada.
   */
   return s;
}

/* EOF */