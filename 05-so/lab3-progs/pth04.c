/*
**  file: pth04.c
**
**  Objetivo:
**  Somar os primeiros N números naturais:
**
**      1 + 2 + 3 + ... + N
**
**  Diferença em relação aos exemplos anteriores:
**
**  - pth02.c e pth03.c usavam tarefas "detached";
**  - aqui a tarefa criada é "joinable".
**
**  Joinable significa:
**  - a tarefa principal pode esperar pela sub-tarefa;
**  - isso é feito com pthread_join();
**  - a tarefa principal também pode receber o valor retornado
**    pela sub-tarefa.
**
**  Neste programa, a soma é dividida em duas partes:
**
**  - sub-tarefa:
**      soma a primeira metade do vetor;
**
**  - tarefa principal:
**      soma a segunda metade do vetor;
**
**  No final:
**  - a tarefa principal espera a sub-tarefa terminar;
**  - recebe a soma parcial calculada pela sub-tarefa;
**  - junta as duas somas parciais;
**  - imprime a soma total.
*/

#include <stdio.h>    /* printf(), perror() */
#include <stdlib.h>   /* exit() */
#include <pthread.h>  /* pthread_create(), pthread_join(), pthread_attr_* */

/*
   Quantidade de números naturais a somar.

   O vetor terá N posições.

   O programa vai calcular:

      1 + 2 + 3 + ... + 1081080
*/
#define N 1081080


/*
   Função que soma os elementos de um vetor.
*/
double soma(double x[], int n);


/*
   Função executada pela sub-tarefa criada com pthread_create().
*/
void *tarefa(void *arg);


/*
   Variáveis globais.

   v[N]:
   - vetor que guarda os números de 1 até N.

   S:
   - soma parcial da tarefa principal;
   - depois passa a guardar a soma total.

   S1:
   - soma parcial calculada pela sub-tarefa.

   Atenção:
   S1 é global de propósito.

   A sub-tarefa retorna o endereço de S1.
   Isso é seguro porque S1 continua a existir mesmo depois
   da função tarefa() terminar.
*/
double v[N], S, S1;


/*
   Estrutura usada para passar argumentos para a sub-tarefa.

   Uma thread criada com pthread_create() só pode receber
   um único argumento do tipo void *.

   Para passar mais de uma informação, usamos uma struct.

   Esta struct guarda:
   - x: ponteiro para o início da parte do vetor que será somada;
   - n: quantidade de elementos que a tarefa deve somar.
*/
typedef struct {
   double *x;
   int n;
} trfarg_t;


int main()
{
   int i, r;

   /*
      trfid:
      identificador da thread criada.
   */
   pthread_t trfid;

   /*
      trfatr:
      atributos da thread.

      Aqui será usado para criar a thread como joinable.
   */
   pthread_attr_t trfatr;

   /*
      trfarg:
      estrutura com os dados enviados para a sub-tarefa.

      Ela vai indicar:
      - onde começa a parte do vetor;
      - quantos elementos devem ser somados.
   */
   trfarg_t trfarg;

   /*
      trfret:
      ponteiro que receberá o valor retornado pela sub-tarefa.

      A sub-tarefa retorna um void *,
      mas na prática esse ponteiro aponta para um double,
      porque a tarefa retorna o endereço de S1.
   */
   double *trfret;

   /*
      Início da tarefa principal.
   */
   printf("\nA iniciar a tarefa principal.\n");

   /*
      Inicializa o vetor com os números naturais:

      v[0] = 1
      v[1] = 2
      v[2] = 3
      ...
      v[N - 1] = N
   */
   for(i = 0; i < N; i++)
      v[i] = i + 1;

   /*
      Inicializa os atributos da thread com valores padrão.
   */
   pthread_attr_init(&trfatr);

   /*
      Define que a thread será joinable.

      PTHREAD_CREATE_JOINABLE significa:
      - a tarefa principal poderá usar pthread_join();
      - a tarefa principal poderá esperar pela sub-tarefa;
      - a tarefa principal poderá recolher o valor retornado.
   */
   pthread_attr_setdetachstate(&trfatr, PTHREAD_CREATE_JOINABLE);

   /*
      Prepara o argumento que será enviado para a sub-tarefa.

      A sub-tarefa ficará responsável pela primeira metade do vetor.

      &v[0]:
      - endereço da primeira posição do vetor.

      N / 2:
      - quantidade de elementos da primeira metade.
   */
   trfarg.x = &v[0];
   trfarg.n = N / 2;

   /*
      Cria a sub-tarefa.

      Argumentos:

      &trfid:
      - onde será guardado o ID da thread criada.

      &trfatr:
      - atributos da thread;
      - neste caso, joinable.

      tarefa:
      - função executada pela sub-tarefa.

      (void *) &trfarg:
      - endereço da estrutura com os dados que a sub-tarefa precisa.

      A partir deste ponto:
      - a sub-tarefa começa a somar a primeira metade;
      - a tarefa principal continua e soma a segunda metade.
   */
   r = pthread_create(&trfid, &trfatr, tarefa, (void *) &trfarg);

   /*
      Se r for diferente de 0, a criação da thread falhou.
   */
   if(r) {
      perror("Erro na criacao da tarefa!");
      exit(1);
   }

   /*
      A tarefa principal soma a segunda metade do vetor.

      &v[N / 2]:
      - endereço da posição onde começa a segunda metade.

      N / 2:
      - quantidade de elementos da segunda metade.

      Exemplo lógico:
      - sub-tarefa soma v[0] até v[(N/2)-1]
      - main soma v[N/2] até v[N-1]
   */
   S = soma(&v[N / 2], N / 2);

   /*
      A tarefa principal espera a sub-tarefa terminar.

      pthread_join() bloqueia a tarefa principal até que
      a sub-tarefa identificada por trfid termine.

      Argumentos:

      trfid:
      - ID da thread que queremos esperar.

      (void **) &trfret:
      - endereço onde será guardado o ponteiro retornado
        pela sub-tarefa.

      Depois desta linha:
      - temos a garantia de que a sub-tarefa terminou;
      - trfret aponta para o resultado parcial dela.
   */
   pthread_join(trfid, (void **) &trfret);

   /*
      Soma o resultado parcial da tarefa principal com o resultado
      parcial da sub-tarefa.

      S:
      - já tem a soma da segunda metade.

      *trfret:
      - acede ao valor apontado por trfret;
      - esse valor é S1, a soma calculada pela sub-tarefa.
   */
   S += *trfret;

   /*
      Imprime a soma total.
   */
   printf(" Soma= %.0lf\n", S);

   /*
      Fim da tarefa principal.
   */
   printf("A terminar a tarefa principal.\n\n");

   return 0;
}


void *tarefa(void *arg)
{
   /*
      Ponteiro para a estrutura de argumentos.

      A thread recebeu arg como void *,
      mas sabemos que ele aponta para uma variável do tipo trfarg_t.
   */
   trfarg_t *a;

   /*
      Início da sub-tarefa.
   */
   printf("A iniciar a sub-tarefa.\n");

   /*
      Converte o ponteiro genérico void * para o tipo correto.

      Depois desta conversão, conseguimos aceder aos campos:

      a->x
      a->n
   */
   a = (trfarg_t *) arg;

   /*
      A sub-tarefa soma a parte do vetor indicada pela estrutura.

      a->x:
      - ponteiro para o início da parte do vetor.

      a->n:
      - quantidade de elementos a somar.

      O resultado fica guardado em S1.
   */
   S1 = soma(a->x, a->n);

   /*
      A sub-tarefa terminou o seu trabalho.
   */
   printf("A terminar a sub-tarefa.\n");

   /*
      Retorna o endereço de S1.

      Isto permite que a tarefa principal receba este endereço
      através de pthread_join().

      Importante:
      Nunca se deve retornar o endereço de uma variável local
      da função tarefa().

      Exemplo errado:

         double resultado;
         return &resultado;

      Isso seria perigoso porque resultado deixaria de existir
      quando tarefa() terminasse.

      Aqui usamos S1 porque ela é global e continua a existir.
   */
   return (void *) &S1;
}


double soma(double x[], int n)
{
   int i;
   double s = 0;

   /*
      Soma os n elementos a partir do endereço recebido em x.
   */
   for(i = 0; i < n; i++)
      s += x[i];

   return s;
}

/* EOF */