/*
**  file: pth01.c
**
**  Objetivo:
**  Somar os primeiros N números naturais:
**
**      1 + 2 + 3 + ... + N
**
**  Este programa é mono-tarefa:
**  - existe apenas a tarefa principal;
**  - essa tarefa começa na função main();
**  - não há criação de threads;
**  - todo o trabalho é feito sequencialmente.
*/

#include <stdio.h>

/*
   Define uma constante chamada N.

   N representa quantos números naturais serão somados.

   Neste caso:
      N = 1081080

   Ou seja, o programa vai somar:

      1 + 2 + 3 + ... + 1081080
*/
#define N 1081080


/*
   Protótipo da função soma().

   Esta função recebe:
   - um vetor de double;
   - a quantidade de elementos desse vetor.

   E devolve:
   - a soma de todos os elementos do vetor.
*/
double soma(double x[], int n);


/*
   Variáveis globais.

   v[N]:
   - vetor com N posições;
   - vai guardar os números naturais de 1 até N.

   S:
   - variável onde será guardada a soma total.

   Como são globais, estas variáveis podem ser usadas
   tanto na função main() como na função soma().
*/
double v[N], S;


int main()
{
   int i;

   /*
      A função main() representa a tarefa principal.

      Como este programa não usa pthread_create(),
      nenhuma outra tarefa/thread é criada.
   */
   printf("\nA iniciar a tarefa principal.\n");

   /*
      Este ciclo preenche o vetor v[] com os números naturais.

      Quando i = 0:
         v[0] = 1

      Quando i = 1:
         v[1] = 2

      Quando i = 2:
         v[2] = 3

      ...

      Quando i = N - 1:
         v[N - 1] = N

      Portanto, no final, o vetor fica assim:

         v[0]     = 1
         v[1]     = 2
         v[2]     = 3
         ...
         v[N - 1] = N
   */
   for(i = 0; i < N; i++)
      v[i] = i + 1;

   /*
      Chama a função soma() para somar todos os elementos
      do vetor v[].

      Argumentos enviados:
      - v  -> início do vetor;
      - N  -> quantidade de elementos a somar.

      O resultado devolvido pela função soma() é guardado
      na variável global S.
   */
   S = soma(v, N);

   /*
      Imprime a soma total.

      %.0lf significa:
      - imprimir um double;
      - sem casas decimais.

      Como a soma de números naturais é um valor inteiro,
      não é necessário mostrar casas decimais.
   */
   printf(" Soma= %.0lf\n", S);

   /*
      Mensagem final da tarefa principal.

      Depois disto, o programa termina normalmente.
   */
   printf("A terminar a tarefa principal.\n\n");

   return 0;
}


/*
   Função soma()

   Esta função soma os n primeiros elementos do vetor x[].

   Parâmetros:
   - x[]: vetor recebido;
   - n: quantidade de elementos que devem ser somados.

   Retorno:
   - devolve a soma total dos elementos.
*/
double soma(double x[], int n)
{
   int i;
   double s = 0;

   /*
      Este ciclo percorre o vetor desde a posição 0
      até à posição n - 1.

      A cada repetição, soma o valor atual de x[i]
      à variável local s.
   */
   for(i = 0; i < n; i++)
      s += x[i];

   /*
      Devolve o valor final da soma.
   */
   return s;
}

/* EOF */