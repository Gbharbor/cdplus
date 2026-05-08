/*
**  file: pth06.c
**
**  Objetivo:
**  Somar os primeiros N números naturais usando várias tarefas.
**
**  Diferença importante em relação ao pth05.c:
**
**  - no pth05.c:
**      cada tarefa guardava sua soma parcial separadamente;
**
**  - aqui:
**      todas as tarefas escrevem diretamente na variável global S.
**
**  Isso é perigoso porque várias threads podem alterar S
**  ao mesmo tempo.
**
**  Este é um exemplo clássico de:
**
**      race condition
**
**  (condição de disputa)
**
**  Race condition acontece quando:
**  - várias threads acedem à mesma variável;
**  - pelo menos uma delas modifica a variável;
**  - e não existe proteção/sincronização.
**
**  O resultado pode ficar errado dependendo da ordem em que
**  o processador executa as threads.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

#define N 1081080
#define MAXTRF 30

/*
   Função que soma um vetor.
*/
double soma(double x[], int n);

/*
   Função executada pelas threads.
*/
void *tarefa(void *arg);

/*
   Variáveis globais.

   v[N]:
   - vetor com os números naturais.

   S:
   - soma total compartilhada entre todas as threads.

   IMPORTANTE:
   Todas as threads alteram S ao mesmo tempo.

   Isso é exatamente o problema deste programa.
*/
double v[N], S;

/*
   Estrutura usada para passar argumentos às tarefas.

   x:
   - início do sub-vetor.

   n:
   - quantidade de elementos a somar.

   i:
   - número da tarefa.
*/
typedef struct {
   double *x;
   int n;
   int i;
} trfarg_t;


int main(int argc, char *argv[])
{
   int i, r, n, va;

   /*
      Vetor com os IDs das threads.
   */
   pthread_t trfid[MAXTRF];

   /*
      Atributos das threads.
   */
   pthread_attr_t trfatr;

   /*
      Estruturas de argumentos das tarefas.
   */
   trfarg_t trfarg[MAXTRF];

   /*
      Validação dos argumentos.
   */
   va = 1;

   if(argc != 2)
      va = 0;
   else {
      n = atoi(argv[1]);

      /*
         Valores permitidos para n.
      */
      if(!((n >= 1 && n <= 15) || n == 20 || n == 30 || n == 120))
         va = 0;
   }

   /*
      Se os argumentos forem inválidos, termina.
   */
   if(!va) {
      printf("\n Utilizacao:  pth05 n\n com n=1-15, 20, 30\n\n");
      exit(1);
   }

   printf("\nA iniciar a tarefa principal(%d).\n", n - 1);

   /*
      Inicializa a soma global com zero.
   */
   S = 0;

   /*
      Preenche o vetor com:

         1, 2, 3, ..., N
   */
   for(i = 0; i < N; i++)
      v[i] = i + 1;

   /*
      Inicializa atributos padrão das threads.
   */
   pthread_attr_init(&trfatr);

   /*
      Threads serão joinable.
   */
   pthread_attr_setdetachstate(&trfatr, PTHREAD_CREATE_JOINABLE);

   /*
      Criação das sub-tarefas.
   */
   for(i = 0; i < n - 1; i++) {

      /*
         Número da tarefa.
      */
      trfarg[i].i = i;

      /*
         Quantidade de elementos que esta tarefa soma.
      */
      trfarg[i].n = N / n;

      /*
         Início do sub-vetor desta tarefa.
      */
      trfarg[i].x = &v[i * N / n];

      /*
         Cria a thread.
      */
      r = pthread_create(&trfid[i], &trfatr, tarefa, (void *) &trfarg[i]);

      /*
         Verifica erro.
      */
      if(r) {
         perror("Erro na criacao da tarefa!");
         exit(1);
      }
   }

   /*
      A tarefa principal também soma sua parte.

      PROBLEMA:
      A tarefa principal também altera S diretamente.

      Então:
      - main altera S
      - threads alteram S
      - tudo possivelmente ao mesmo tempo

      Isso cria race condition.
   */
   S += soma(&v[(n - 1) * N / n], N / n);

   /*
      Espera todas as sub-tarefas terminarem.
   */
   for(i = 0; i < n - 1; i++)
      pthread_join(trfid[i], (void **) NULL);

   /*
      Imprime a soma total.

      Às vezes o valor pode sair correto.
      Às vezes pode sair errado.

      Isso depende da ordem de execução das threads.
   */
   printf("Soma= %.0lf\n", S);

   printf("A terminar a tarefa principal(%d).\n", n - 1);

   return 0;
}


void *tarefa(void *arg)
{
   trfarg_t *a;

   /*
      Variáveis não usadas neste exemplo.
   */
   double L, P;

   /*
      Converte void * para o tipo correto.
   */
   a = (trfarg_t *) arg;

   printf("A iniciar a sub-tarefa(%d).\n", a->i);

   /*
      Aqui está o problema principal do programa.

      Todas as threads fazem:

         S += alguma_coisa

      ao mesmo tempo.

      Parece simples, mas:

         S += valor

      NÃO é uma operação única.

      Internamente acontece algo parecido com:

         1. ler S
         2. somar valor
         3. gravar novo S

      Imagine:

         Thread A lê S = 100
         Thread B lê S = 100

         Thread A soma +50 → grava 150
         Thread B soma +30 → grava 130

      Resultado final:
         130

      Mas o correto seria:
         180

      Uma atualização foi perdida.

      Isso é race condition.
   */
   S += soma(a->x, a->n);

   printf("A terminar a sub-tarefa(%d).\n", a->i);

   return (void *) NULL;
}


double soma(double x[], int n)
{
   int i;
   double s = 0;

   /*
      Soma os elementos do sub-vetor.
   */
   for(i = 0; i < n; i++)
      s += x[i];

   return s;
}

/* EOF */