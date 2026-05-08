/*
**  file: pth07.c
**
**  Objetivo:
**  Somar os primeiros N números naturais usando várias tarefas.
**
**  Este programa é parecido com o pth06.c, mas aqui a race condition
**  fica muito mais provável de acontecer.
**
**  No pth06.c existia:
**
**      S += soma(a->x, a->n);
**
**  Aqui o código foi separado em duas etapas:
**
**      L = S;
**      S = L + soma(a->x, a->n);
**
**  Logicamente parece a mesma coisa, mas em multitarefa isto é perigoso.
**
**  Por quê?
**
**  Porque entre o momento em que uma thread lê S e o momento em que
**  escreve o novo valor em S, outra thread pode alterar S.
**
**  Resultado:
**  - algumas somas parciais podem ser perdidas;
**  - o valor final pode sair errado;
**  - o erro depende da ordem de execução das threads.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

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
   - vetor com os números de 1 até N.

   S:
   - variável global onde todas as tarefas acumulam a soma.

   Problema:
   S é compartilhada e modificada por várias threads sem mutex.
*/
double v[N], S;

/*
   Estrutura usada para enviar dados para cada tarefa.

   x:
   - início do sub-vetor que a tarefa vai somar.

   n:
   - quantidade de elementos que a tarefa vai somar.

   i:
   - índice da tarefa, usado nas mensagens.
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
      Vetor com os identificadores das threads.
   */
   pthread_t trfid[MAXTRF];

   /*
      Atributos usados na criação das threads.
   */
   pthread_attr_t trfatr;

   /*
      Vetor com os argumentos de cada thread.
   */
   trfarg_t trfarg[MAXTRF];

   /*
      Validação dos argumentos da linha de comandos.

      O programa espera receber o número de tarefas.
   */
   va = 1;

   if(argc != 2)
      va = 0;
   else {
      n = atoi(argv[1]);

      /*
         Valores aceites para n.
      */
      if(!((n >= 1 && n <= 15) || n == 20 || n == 30 || n == 120))
         va = 0;
   }

   /*
      Se o argumento for inválido, mostra a utilização correta
      e termina o programa.
   */
   if(!va) {
      printf("\n Utilizacao:  pth05 n\n com n=1-15, 20, 30\n\n");
      exit(1);
   }

   printf("\nA iniciar a tarefa principal(%d).\n", n - 1);

   /*
      Inicializa a soma global.

      Todas as tarefas vão tentar atualizar esta mesma variável.
   */
   S = 0;

   /*
      Preenche o vetor com os números naturais:

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

      Assim, a tarefa principal poderá esperar por elas
      usando pthread_join().
   */
   pthread_attr_setdetachstate(&trfatr, PTHREAD_CREATE_JOINABLE);

   /*
      Cria n - 1 sub-tarefas.

      A última parte da soma fica para a tarefa principal.
   */
   for(i = 0; i < n - 1; i++) {
      /*
         Índice da tarefa.
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

      /*
         Se houver erro na criação da thread, termina.
      */
      if(r) {
         perror("Erro na criacao da tarefa!");
         exit(1);
      }
   }

   /*
      A tarefa principal soma o último segmento.

      Atenção:
      Aqui também há acesso direto à variável global S.

      Enquanto a main faz esta atualização, outras threads também
      podem estar a atualizar S.
   */
   S += soma(&v[(n - 1) * N / n], N / n);

   /*
      A tarefa principal espera todas as sub-tarefas terminarem.
   */
   for(i = 0; i < n - 1; i++)
      pthread_join(trfid[i], (void **) NULL);

   /*
      Imprime o valor final de S.

      Neste programa, o valor pode estar errado por causa
      da race condition.
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
      Converte o argumento genérico para o tipo correto.
   */
   a = (trfarg_t *) arg;

   printf("A iniciar a sub-tarefa(%d).\n", a->i);

   /*
      Aqui começa o problema.

      A variável S é global e está a ser partilhada por todas
      as tarefas.

      Nenhuma proteção está a ser usada.
      Não há mutex.
      Não há exclusão mútua.
   */

   /*
      Primeiro, a thread lê o valor atual de S e guarda em L.

      Exemplo:
         S = 100
         L = 100

      O problema é que, depois desta leitura, outra thread pode
      ser executada e alterar S antes desta thread continuar.
   */
   L = S;

   /*
      Depois, a thread calcula:

         novo S = valor antigo de S + soma parcial

      Mas o "valor antigo de S" está guardado em L.

      Se outra thread alterou S depois do L = S, esta linha usa
      um valor desatualizado.

      Exemplo:

         S começa em 100

         Thread A:
            L = S;       // L = 100

         Thread B:
            L = S;       // L = 100
            S = L + 30;  // S = 130

         Thread A:
            S = L + 50;  // S = 150

      Resultado final:
         S = 150

      Resultado correto:
         S = 180

      A soma parcial da Thread B foi perdida.
   */
   S = L + soma(a->x, a->n);

   /*
      Como a soma(a->x, a->n) demora algum tempo,
      aumenta a probabilidade de outra thread alterar S
      entre a leitura e a escrita.

      Por isso este exemplo tem maior probabilidade de erro
      do que o pth06.c.
   */

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