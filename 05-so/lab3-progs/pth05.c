/*
**  file: pth05.c
**
**  Objetivo:
**  Somar os primeiros N números naturais:
**
**      1 + 2 + 3 + ... + N
**
**  Este programa é multi-tarefa.
**
**  O número total de tarefas é escolhido pelo utilizador
**  através da linha de comandos.
**
**  Exemplo:
**
**      ./pth05 15
**
**  Neste caso, o programa usa 15 tarefas no total.
**
**  Atenção:
**  A tarefa principal também conta como uma tarefa.
**
**  Se n = 15:
**  - são criadas 14 sub-tarefas;
**  - a tarefa principal faz a 15.ª parte do trabalho.
**
**  Divisão do trabalho:
**
**  - cada tarefa soma N / n elementos;
**  - cada sub-tarefa guarda a sua soma parcial dentro
**    da própria estrutura de argumentos;
**  - a tarefa principal soma a sua parte;
**  - depois espera todas as sub-tarefas terminarem;
**  - por fim, junta todas as somas parciais.
*/

#include <stdio.h>    /* printf(), perror() */
#include <stdlib.h>   /* atoi(), exit() */
#include <pthread.h>  /* pthread_create(), pthread_join(), pthread_attr_* */

/*
   N é a quantidade total de números naturais a somar.

   O programa calcula:

      1 + 2 + 3 + ... + 1081080

   Este valor foi escolhido porque é divisível por vários
   valores de n usados no laboratório:
   1 a 15, 20 e 30.

   Isso facilita dividir o trabalho igualmente entre as tarefas.
*/
#define N 1081080

/*
   Número máximo de tarefas permitido pelo programa.

   Como o enunciado aceita no máximo 30 tarefas,
   os vetores de IDs e argumentos terão tamanho 30.
*/
#define MAXTRF 30


/*
   Função que soma os elementos de um vetor.
*/
double soma(double x[], int n);


/*
   Função executada pelas sub-tarefas criadas com pthread_create().
*/
void *tarefa(void *arg);


/*
   Variáveis globais.

   v[N]:
   - vetor com os números naturais de 1 até N.

   S:
   - inicialmente guarda a soma parcial da tarefa principal;
   - depois passa a guardar a soma total.
*/
double v[N], S;


/*
   Estrutura usada como argumento das tarefas.

   Cada thread criada recebe um único argumento void *.
   Para enviar várias informações, usamos uma struct.

   Campos:

   x:
   - ponteiro para o início do sub-vetor que a tarefa deve somar.

   s:
   - soma parcial calculada pela tarefa.
   - funciona como "saída" da tarefa.

   n:
   - quantidade de elementos que a tarefa deve somar.

   i:
   - número/índice da tarefa.
   - usado apenas para identificar as mensagens no ecrã.
*/
typedef struct {
   double *x;
   double s;
   int n;
   int i;
} trfarg_t;


int main(int argc, char *argv[])
{
   int i, r, n, va;

   /*
      trfid[MAXTRF]:
      vetor com os identificadores das threads criadas.

      Se n = 15:
      - serão criadas 14 sub-tarefas;
      - os IDs ficam em trfid[0] até trfid[13].
   */
   pthread_t trfid[MAXTRF];

   /*
      trfatr:
      atributos usados na criação das threads.

      Todas serão criadas como joinable.
   */
   pthread_attr_t trfatr;

   /*
      trfarg[MAXTRF]:
      vetor de estruturas.

      Cada sub-tarefa recebe uma posição deste vetor
      como argumento.

      Exemplo:
      - tarefa 0 recebe &trfarg[0]
      - tarefa 1 recebe &trfarg[1]
      - tarefa 2 recebe &trfarg[2]
   */
   trfarg_t trfarg[MAXTRF];

   /*
      Validação dos argumentos da linha de comandos.

      argc indica quantos argumentos foram passados.

      Exemplo:
         ./pth05 15

      argc será 2:
      - argv[0] = "./pth05"
      - argv[1] = "15"

      O programa exige exatamente 1 argumento depois
      do nome do programa.
   */
   va = 1;

   if(argc != 2)
      va = 0;
   else {
      /*
         atoi() converte texto para inteiro.

         argv[1] vem como string.
         Exemplo: "15"

         Depois de atoi(argv[1]):
         n = 15
      */
      n = atoi(argv[1]);

      /*
         O programa só aceita:
         - n entre 1 e 15;
         - n igual a 20;
         - n igual a 30.

         Estes valores foram escolhidos porque N é divisível por eles.
      */
      if(!((n >= 1 && n <= 15) || n == 20 || n == 30))
         va = 0;
   }

   /*
      Se os argumentos forem inválidos, mostra a forma correta
      de utilização e termina o programa.
   */
   if(!va) {
      printf("\n Utilizacao:  pth05 n\n com n=1-15, 20, 30\n\n");
      exit(1);
   }

   /*
      A tarefa principal recebe o índice n - 1.

      Exemplo:
      se n = 15:
      - sub-tarefas: 0 até 13;
      - tarefa principal: 14.
   */
   printf("\nA iniciar a tarefa principal(%d).\n", n - 1);

   /*
      Inicializa o vetor com os números naturais:

      v[0] = 1
      v[1] = 2
      ...
      v[N - 1] = N
   */
   for(i = 0; i < N; i++)
      v[i] = i + 1;

   /*
      Inicializa os atributos das threads com valores padrão.
   */
   pthread_attr_init(&trfatr);

   /*
      Define que as threads criadas serão joinable.

      Isso permite que a tarefa principal espere por elas
      usando pthread_join().
   */
   pthread_attr_setdetachstate(&trfatr, PTHREAD_CREATE_JOINABLE);

   /*
      Criação das sub-tarefas.

      O ciclo vai de 0 até n - 2.

      Por quê n - 2?
      Porque a última parte do trabalho fica para a tarefa principal,
      que é considerada a tarefa número n - 1.

      Exemplo com n = 15:
      - cria sub-tarefas 0 até 13;
      - tarefa principal é a 14.
   */
   for(i = 0; i < n - 1; i++) {
      /*
         Guarda o número da tarefa.

         Este campo é usado apenas nas mensagens:
            A iniciar a sub-tarefa(i)
            A terminar a sub-tarefa(i)
      */
      trfarg[i].i = i;

      /*
         Cada tarefa soma exatamente N / n elementos.

         Exemplo:
         se N = 1081080 e n = 15:

            N / n = 72072

         Cada tarefa soma 72072 posições do vetor.
      */
      trfarg[i].n = N / n;

      /*
         Define onde começa o sub-vetor desta tarefa.

         A tarefa i começa na posição:

            i * N / n

         Exemplo com n = 15:

         tarefa 0:
            começa em v[0]

         tarefa 1:
            começa em v[72072]

         tarefa 2:
            começa em v[144144]

         e assim por diante.
      */
      trfarg[i].x = &v[i * N / n];

      /*
         Cria a sub-tarefa.

         Argumentos:

         &trfid[i]:
         - guarda o ID da thread criada.

         &trfatr:
         - atributos da thread;
         - aqui, joinable.

         tarefa:
         - função que a thread vai executar.

         (void *) &trfarg[i]:
         - endereço da estrutura com os dados da tarefa.
      */
      r = pthread_create(&trfid[i], &trfatr, tarefa, (void *) &trfarg[i]);

      /*
         Verifica se houve erro ao criar a thread.
      */
      if(r) {
         perror("Erro na criacao da tarefa!");
         exit(1);
      }
   }

   /*
      A última parte da soma fica para a tarefa principal.

      A tarefa principal é considerada a tarefa n - 1.

      Ela começa na posição:

         (n - 1) * N / n

      E soma também N / n elementos.
   */
   S = soma(&v[(n - 1) * N / n], N / n);

   /*
      Agora a tarefa principal espera todas as sub-tarefas
      terminarem.

      Para cada sub-tarefa:
      - pthread_join() espera a thread terminar;
      - depois a soma parcial dessa thread é adicionada a S.

      Aqui o retorno da thread não é usado.

      Por isso, o segundo argumento de pthread_join() é NULL.

      A soma parcial vem de:
         trfarg[i].s

      Ou seja:
      A própria estrutura enviada como argumento também é usada
      para devolver o resultado.
   */
   for(i = 0; i < n - 1; i++) {
      pthread_join(trfid[i], (void **) NULL);
      S += trfarg[i].s;
   }

   /*
      Imprime a soma total.
   */
   printf("Soma= %.0lf\n", S);

   /*
      Fim da tarefa principal.
   */
   printf("A terminar a tarefa principal(%d).\n", n - 1);

   return 0;
}


void *tarefa(void *arg)
{
   /*
      Ponteiro para a estrutura de argumentos da tarefa.
   */
   trfarg_t *a;

   /*
      Converte o ponteiro genérico void * para trfarg_t *.

      pthread_create() envia argumentos como void *,
      por isso precisamos converter para o tipo correto.
   */
   a = (trfarg_t *) arg;

   /*
      Mostra que a sub-tarefa começou.

      O índice a->i identifica qual sub-tarefa está a executar.
   */
   printf("A iniciar a sub-tarefa(%d).\n", a->i);

   /*
      Calcula a soma parcial da sub-tarefa.

      a->x:
      - início do sub-vetor.

      a->n:
      - quantidade de elementos a somar.

      O resultado é guardado em a->s.

      Aqui está uma diferença em relação ao pth04.c:

      - pth04.c retornava a soma parcial pelo return da thread;
      - pth05.c guarda a soma parcial dentro da struct.
   */
   a->s = soma(a->x, a->n);

   /*
      Mostra que a sub-tarefa terminou.
   */
   printf("A terminar a sub-tarefa(%d).\n", a->i);

   /*
      A thread retorna NULL porque o resultado já foi guardado
      em a->s.
   */
   return (void *) NULL;
}


double soma(double x[], int n)
{
   int i;
   double s = 0;

   /*
      Soma os n elementos a partir do endereço x.
   */
   for(i = 0; i < n; i++)
      s += x[i];

   return s;
}

/* EOF */