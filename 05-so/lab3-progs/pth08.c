/*
**  file: pth08.c
**
**  Objetivo:
**  Somar os primeiros N números naturais usando várias tarefas.
**
**  Este programa corrige o problema do pth07.c usando um mutex.
**
**  Problema anterior:
**  - várias tarefas alteravam a variável global S ao mesmo tempo;
**  - isso podia causar race condition;
**  - algumas somas parciais podiam ser perdidas.
**
**  Solução aqui:
**  - usar pthread_mutex_lock() antes de alterar S;
**  - usar pthread_mutex_unlock() depois de alterar S.
**
**  Mutex significa "mutual exclusion", ou exclusão mútua.
**
**  Na prática:
**  - só uma tarefa de cada vez pode entrar na região crítica;
**  - as outras tarefas ficam à espera;
**  - assim, S é atualizada de forma segura.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 1081080
#define MAXTRF 30

/*
   Função que soma elementos de um vetor.
*/
double soma(double x[], int n);

/*
   Função executada pelas sub-tarefas.
*/
void *tarefa(void *arg);

/*
   Variáveis globais.

   v[N]:
   - vetor com os números naturais.

   S:
   - soma total compartilhada entre todas as tarefas.

   Agora S será protegida por um mutex.
*/
double v[N], S;

/*
   Estrutura usada como argumento de cada tarefa.

   x:
   - início do sub-vetor.

   n:
   - quantidade de elementos a somar.

   i:
   - índice da tarefa.
*/
typedef struct {
   double *x;
   int n;
   int i;
} trfarg_t;

/*
   Mutex global.

   Como todas as threads precisam usar o mesmo mutex,
   ele é declarado globalmente.

   Este mutex será usado para proteger a variável S.
*/
pthread_mutex_t mtx;


int main(int argc, char *argv[])
{
   int i, r, n, va;
   double P;

   /*
      Vetor com os identificadores das threads.
   */
   pthread_t trfid[MAXTRF];

   /*
      Atributos das threads.
   */
   pthread_attr_t trfatr;

   /*
      Argumentos enviados para cada thread.
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
         Valores permitidos para o número de tarefas.
      */
      if(!((n >= 1 && n <= 15) || n == 20 || n == 30))
         va = 0;
   }

   if(!va) {
      printf("\n Utilizacao:  pth05 n\n com n=1-15, 20, 30\n\n");
      exit(1);
   }

   printf("\nA iniciar a tarefa principal(%d).\n", n - 1);

   /*
      Inicializa a soma global.
   */
   S = 0;

   /*
      Preenche o vetor:

         v[0] = 1
         v[1] = 2
         ...
         v[N - 1] = N
   */
   for(i = 0; i < N; i++)
      v[i] = i + 1;

   /*
      Inicializa os atributos das threads.
   */
   pthread_attr_init(&trfatr);

   /*
      Define as threads como joinable.

      Assim, a tarefa principal pode esperar cada uma terminar
      com pthread_join().
   */
   pthread_attr_setdetachstate(&trfatr, PTHREAD_CREATE_JOINABLE);

   /*
      Inicializa o mutex.

      O segundo argumento NULL significa:
      usar os atributos padrão do mutex.
   */
   pthread_mutex_init(&mtx, NULL);

   /*
      Cria n - 1 sub-tarefas.

      A última parte da soma fica para a tarefa principal.
   */
   for(i = 0; i < n - 1; i++) {
      /*
         Número da sub-tarefa.
      */
      trfarg[i].i = i;

      /*
         Cada tarefa soma N / n elementos.
      */
      trfarg[i].n = N / n;

      /*
         Define o início do sub-vetor desta tarefa.
      */
      trfarg[i].x = &v[i * N / n];

      /*
         Cria a thread.
      */
      r = pthread_create(&trfid[i], &trfatr, tarefa, (void *) &trfarg[i]);

      if(r) {
         perror("Erro na criacao da tarefa!");
         exit(1);
      }
   }

   /*
      A tarefa principal calcula a sua soma parcial fora do mutex.

      Isso é importante porque soma() pode demorar algum tempo.

      O ideal é manter a região crítica pequena.

      Aqui P recebe a soma parcial da tarefa principal.
   */
   P = soma(&v[(n - 1) * N / n], N / n);

   /*
      Entra na região crítica.

      A partir daqui, a tarefa principal tem acesso exclusivo
      à variável S.
   */
   pthread_mutex_lock(&mtx);

   /*
      Atualiza S com a soma parcial da tarefa principal.

      Esta operação está protegida pelo mutex.
   */
   S += P;

   /*
      Sai da região crítica.

      Depois desta chamada, outra thread pode entrar e alterar S.
   */
   pthread_mutex_unlock(&mtx);

   /*
      Espera todas as sub-tarefas terminarem.
   */
   for(i = 0; i < n - 1; i++)
      pthread_join(trfid[i], (void **) NULL);

   /*
      Destrói o mutex.

      Depois que todas as threads terminaram, o mutex já não é
      necessário.
   */
   pthread_mutex_destroy(&mtx);

   /*
      Imprime a soma total.

      Agora o resultado deve sair correto, porque S foi protegida
      com exclusão mútua.
   */
   printf("Soma= %.0lf\n", S);

   printf("A terminar a tarefa principal(%d).\n", n - 1);

   return 0;
}


void *tarefa(void *arg)
{
   trfarg_t *a;
   double L;

   /*
      Converte o argumento genérico void * para trfarg_t *.
   */
   a = (trfarg_t *) arg;

   printf("A iniciar a sub-tarefa(%d).\n", a->i);

   /*
      Entra na região crítica.

      Se outra thread já estiver dentro desta zona,
      esta thread fica bloqueada até o mutex ser libertado.

      O objetivo é proteger a variável global S.
   */
   pthread_mutex_lock(&mtx);

   /*
      Este código continua logicamente equivalente a:

         S += soma(a->x, a->n);

      Mas agora está protegido pelo mutex.

      Mesmo que a soma demore, nenhuma outra thread consegue
      alterar S enquanto esta thread estiver dentro da região crítica.
   */
   L = S;
   S = L + soma(a->x, a->n);

   /*
      Sai da região crítica.

      A partir daqui, outra thread pode atualizar S.
   */
   pthread_mutex_unlock(&mtx);

   printf("A terminar a sub-tarefa(%d).\n", a->i);

   return (void *) NULL;
}


double soma(double x[], int n)
{
   int i;
   double s = 0;

   /*
      Soma os n elementos recebidos.
   */
   for(i = 0; i < n; i++)
      s += x[i];

   return s;
}

/* EOF */