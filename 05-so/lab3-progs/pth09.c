/*
**  file: pth09.c
**
**  Objetivo:
**  Somar os primeiros N números naturais usando várias tarefas.
**
**  Esta é a versão final correta.
**
**  Ela usa mutex para proteger a variável global S, mas faz isso
**  de forma mais eficiente que o pth08.c.
**
**  Diferença principal:
**
**  - no pth08.c:
**      a tarefa entrava no mutex e fazia a soma dentro da região crítica;
**
**  - no pth09.c:
**      a tarefa calcula primeiro a soma parcial fora do mutex;
**      depois entra no mutex apenas para atualizar S.
**
**  Isto é melhor porque a região crítica fica muito pequena.
**
**  Regra importante:
**  Dentro do mutex deve ficar apenas o código que realmente precisa
**  de exclusão mútua.
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
   - soma total compartilhada por todas as tarefas.

   Como S é modificada por várias threads, ela precisa ser
   protegida por mutex.
*/
double v[N], S;

/*
   Estrutura usada como argumento de cada tarefa.

   x:
   - início do sub-vetor.

   n:
   - quantidade de elementos que a tarefa deve somar.

   i:
   - índice da tarefa.
*/
typedef struct {
   double *x;
   int n;
   int i;
} trfarg_t;

/*
   Mutex global usado para proteger o acesso à variável S.
*/
pthread_mutex_t mtx;


int main(int argc, char *argv[])
{
   int i, r, n, va;
   double P;

   /*
      Vetor com os identificadores das threads criadas.
   */
   pthread_t trfid[MAXTRF];

   /*
      Atributos usados na criação das threads.
   */
   pthread_attr_t trfatr;

   /*
      Argumentos enviados para cada thread.
   */
   trfarg_t trfarg[MAXTRF];

   /*
      Validação do argumento recebido pela linha de comandos.
   */
   va = 1;

   if(argc != 2)
      va = 0;
   else {
      n = atoi(argv[1]);

      /*
         O programa só aceita valores de n que dividem N exatamente.
      */
      if(!((n >= 1 && n <= 15) || n == 20 || n == 30))
         va = 0;
   }

   /*
      Se o argumento for inválido, o programa termina.
   */
   if(!va) {
      printf("\n Utilizacao:  pth05 n\n com n=1-15, 20, 30\n\n");
      exit(1);
   }

   printf("\nA iniciar a tarefa principal(%d).\n", n - 1);

   /*
      Inicializa a soma total.
   */
   S = 0;

   /*
      Preenche o vetor com os números naturais:

         1, 2, 3, ..., N
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
      Inicializa o mutex com atributos padrão.
   */
   pthread_mutex_init(&mtx, NULL);

   /*
      Cria n - 1 sub-tarefas.

      A última parte da soma será feita pela tarefa principal.
   */
   for(i = 0; i < n - 1; i++) {
      /*
         Número da tarefa.
      */
      trfarg[i].i = i;

      /*
         Cada tarefa soma N / n elementos.
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

      if(r) {
         perror("Erro na criacao da tarefa!");
         exit(1);
      }
   }

   /*
      A tarefa principal calcula a sua soma parcial fora do mutex.

      Isto é eficiente porque a função soma() pode demorar.
      Não faz sentido bloquear as outras tarefas durante esse cálculo.
   */
   P = soma(&v[(n - 1) * N / n], N / n);

   /*
      Entra na região crítica.

      A partir daqui, a tarefa principal tem acesso exclusivo à variável S.
   */
   pthread_mutex_lock(&mtx);

   /*
      Atualiza S com a soma parcial da tarefa principal.

      Esta é a única operação que realmente precisa de proteção.
   */
   S += P;

   /*
      Sai da região crítica.

      Outras threads podem agora atualizar S.
   */
   pthread_mutex_unlock(&mtx);

   /*
      Espera todas as sub-tarefas terminarem.

      Depois deste ciclo, temos garantia de que todas já somaram
      as suas partes em S.
   */
   for(i = 0; i < n - 1; i++)
      pthread_join(trfid[i], (void **) NULL);

   /*
      Destrói o mutex.

      Como já não haverá mais acesso concorrente a S,
      o mutex não é mais necessário.
   */
   pthread_mutex_destroy(&mtx);

   /*
      Imprime a soma total.
   */
   printf("Soma= %.0lf\n", S);

   printf("A terminar a tarefa principal(%d).\n", n - 1);

   return 0;
}


void *tarefa(void *arg)
{
   trfarg_t *a;
   double P;

   /*
      Converte o argumento genérico recebido pela thread
      para o tipo correto.
   */
   a = (trfarg_t *) arg;

   printf("A iniciar a sub-tarefa(%d).\n", a->i);

   /*
      Calcula a soma parcial fora da região crítica.

      Isto é o ponto mais importante desta versão.

      A variável global S ainda não é tocada aqui.
      Portanto, não há necessidade de mutex nesta parte.
   */
   P = soma(a->x, a->n);

   /*
      Entra na região crítica apenas no momento de alterar S.
   */
   pthread_mutex_lock(&mtx);

   /*
      Atualiza a soma global.

      Como esta operação mexe na variável compartilhada S,
      precisa estar protegida pelo mutex.
   */
   S += P;

   /*
      Liberta o mutex rapidamente.

      A região crítica foi curta:
      apenas uma atualização simples.
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