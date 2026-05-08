/*
**  file: pth03.c
**
**  Objetivo:
**  Somar os primeiros N números naturais:
**
**      1 + 2 + 3 + ... + N
**
**  Este programa é tri-tarefa:
**
**  1. tarefa principal
**     - executa a função main()
**     - cria a sub-tarefa1
**
**  2. sub-tarefa1
**     - executa a função tarefa1()
**     - cria a sub-sub-tarefa2
**     - termina logo depois de criar a tarefa2
**
**  3. sub-sub-tarefa2
**     - executa a função tarefa2()
**     - faz a soma total
**
**  Ambas as tarefas criadas são "detached".
**
**  Isso significa:
**  - a tarefa principal não usa pthread_join();
**  - tarefa1 também não usa pthread_join();
**  - quando tarefa1 e tarefa2 terminam, os seus recursos
**    são libertados automaticamente.
**
**  Ideia principal deste exemplo:
**
**  Mesmo que tarefa1 termine antes da tarefa2, a tarefa2
**  continua a executar, porque todas pertencem ao mesmo processo.
**
**  Atenção:
**  Se a tarefa principal terminar, o processo inteiro termina.
**  Por isso existe sleep(4), para dar tempo das outras tarefas
**  terminarem antes do fim da main().
*/

#include <pthread.h>   /* pthread_create(), pthread_attr_init(), etc. */
#include <stdio.h>     /* printf(), perror() */
#include <stdlib.h>    /* exit() */
#include <sys/types.h> /* tipos do sistema */
#include <unistd.h>    /* getpid(), sleep() */

/*
   Quantidade de números naturais a somar.

   O programa vai calcular:

      1 + 2 + 3 + ... + 1081080
*/
#define N 1081080


/*
   Função que soma os elementos de um vetor.
*/
double soma(double x[], int n);


/*
   Função executada pela primeira sub-tarefa.

   A tarefa principal cria uma thread que começa nesta função.
*/
void *tarefa1(void *arg);


/*
   Função executada pela segunda sub-tarefa.

   A tarefa1 cria uma thread que começa nesta função.
   Esta é a função que realmente calcula a soma.
*/
void *tarefa2(void *arg);


/*
   Variáveis globais.

   v[N]:
   - vetor onde serão guardados os números naturais.

   S:
   - variável onde será guardada a soma total.

   Como são globais, todas as tarefas do processo podem aceder:
   - main()
   - tarefa1()
   - tarefa2()
*/
double v[N], S;


int main()
{
   int i, r;

   /*
      trfid:
      guarda o identificador da thread criada.

      Neste caso, será o identificador da tarefa1.
   */
   pthread_t trfid;

   /*
      trfatr:
      guarda os atributos usados na criação da thread.

      Será configurada para criar uma thread detached.
   */
   pthread_attr_t trfatr;

   /*
      A tarefa principal começa aqui.

      getpid() mostra o PID do processo.

      Como threads pertencem ao mesmo processo,
      main(), tarefa1() e tarefa2() deverão mostrar o mesmo PID.
   */
   printf("\nA iniciar a tarefa principal: PID=%d\n", (int) getpid());

   /*
      Inicializa o vetor v[] com os números naturais.

      v[0] = 1
      v[1] = 2
      v[2] = 3
      ...
      v[N - 1] = N
   */
   for(i = 0; i < N; i++)
      v[i] = i + 1;

   /*
      Inicializa os atributos da thread com os valores padrão.

      Isto é necessário antes de alterar qualquer atributo.
   */
   pthread_attr_init(&trfatr);

   /*
      Define que a thread será criada como detached.

      Detached significa:
      - não será necessário fazer pthread_join();
      - os recursos serão libertados automaticamente quando terminar;
      - a thread executa de forma independente da thread que a criou.
   */
   pthread_attr_setdetachstate(&trfatr, PTHREAD_CREATE_DETACHED);

   /*
      Cria a primeira sub-tarefa.

      Argumentos:

      &trfid:
      - onde será guardado o ID da thread criada.

      &trfatr:
      - atributos da thread;
      - neste caso, detached.

      tarefa1:
      - função onde a nova thread começa a executar.

      (void *) NULL:
      - argumento passado para tarefa1();
      - neste exemplo não é usado nenhum argumento.
   */
   r = pthread_create(&trfid, &trfatr, tarefa1, (void *) NULL);

   /*
      Se pthread_create() devolver valor diferente de 0,
      significa que a criação da thread falhou.
   */
   if(r) {
      perror("Erro na criacao da tarefa1!");
      exit(1);
   }

   /*
      Como tarefa1 e tarefa2 são detached, a tarefa principal
      não espera por elas com pthread_join().

      Por isso, o programa usa sleep(4).

      sleep(4) bloqueia a tarefa principal durante 4 segundos,
      dando tempo para:
      - tarefa1 iniciar;
      - tarefa1 criar tarefa2;
      - tarefa1 terminar;
      - tarefa2 calcular a soma;
      - tarefa2 imprimir o resultado;
      - tarefa2 terminar.

      Se a main() terminasse imediatamente, o processo inteiro
      acabaria e as outras threads poderiam ser interrompidas.
   */
   sleep(4);

   /*
      A tarefa principal termina.

      Quando a main() termina, o processo termina também.
   */
   printf("A terminar a tarefa principal.\n\n");

   return 0;
}


void *tarefa1(void *arg)
{
   int r;

   /*
      Esta variável guarda o identificador da tarefa2.

      Como tarefa2 será criada dentro de tarefa1(), o ID dela
      é guardado aqui.
   */
   pthread_t trfid;

   /*
      Atributos usados para criar tarefa2.
   */
   pthread_attr_t trfatr;

   /*
      Início da primeira sub-tarefa.

      Esta tarefa não faz a soma.
      Ela apenas cria outra thread.
   */
   printf("A iniciar a sub-tarefa1: PID=%d\n", (int) getpid());

   /*
      Inicializa os atributos da tarefa2 com valores padrão.
   */
   pthread_attr_init(&trfatr);

   /*
      Define tarefa2 como detached.
   */
   pthread_attr_setdetachstate(&trfatr, PTHREAD_CREATE_DETACHED);

   /*
      Cria a segunda sub-tarefa.

      A partir daqui, tarefa2 começa a executar a função tarefa2().
   */
   r = pthread_create(&trfid, &trfatr, tarefa2, (void *) NULL);

   /*
      Verifica se houve erro ao criar tarefa2.
   */
   if(r) {
      perror("Erro na criacao da tarefa2!");
      exit(1);
   }

   /*
      tarefa1 termina logo depois de criar tarefa2.

      Isto é o ponto principal do exemplo:
      tarefa1 termina, mas tarefa2 continua a executar.

      Por quê?
      Porque tarefa2 pertence ao processo inteiro, não depende
      da existência contínua de tarefa1.
   */
   printf("A terminar a sub-tarefa1.\n");

   return (void *) NULL;
}


void *tarefa2(void *arg)
{
   /*
      Esta é a sub-sub-tarefa.

      Ela foi criada por tarefa1(), não diretamente pela main().
   */
   printf("A iniciar a sub-sub-tarefa2: PID=%d\n", (int) getpid());

   /*
      Calcula a soma total usando o vetor global v[].

      Como v[] foi preenchido pela tarefa principal antes da criação
      das threads, tarefa2 já encontra o vetor pronto.
   */
   S = soma(v, N);

   /*
      Imprime a soma total.
   */
   printf(" Soma= %.0lf\n", S);

   /*
      Termina a sub-sub-tarefa.
   */
   printf("A terminar a sub-sub-tarefa2.\n");

   return (void *) NULL;
}


double soma(double x[], int n)
{
   int i;
   double s = 0;

   /*
      Percorre o vetor x[] e acumula todos os valores em s.
   */
   for(i = 0; i < n; i++)
      s += x[i];

   return s;
}

/* EOF */