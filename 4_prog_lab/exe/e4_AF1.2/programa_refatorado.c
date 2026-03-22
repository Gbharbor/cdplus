#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define CAPACIDADE_INICIAL 10
#define TAM_NOME 100

// Estrutura para armazenar dados de um estudante
typedef struct {
   char nome[TAM_NOME];
   float nota;
} Estudante;

// Estrutura para gerir a lista de estudantes
// Removi variaveis globais, e coloquei tudo dentro de uma Struct
typedef struct {
   Estudante *dados;
   int quantidade;
   int capacidade;
} ListaEstudantes;

// Protótipos das funções: declarações antecipadas das funções
void inicializarLista(ListaEstudantes *lista);
void libertarLista(ListaEstudantes *lista);
int aumentarCapacidade(ListaEstudantes *lista);
void limparBuffer(void);
void removerNewline(char *str);
int lerInteiro(const char *mensagem, int *valor);
int lerFloat(const char *mensagem, float *valor);
void lerString(const char *mensagem, char *destino, int tamanho);
int adicionarEstudante(ListaEstudantes *lista, const char *nome, float nota);
float calcularMedia(const ListaEstudantes *lista);
void listarEstudantes(const ListaEstudantes *lista);

// Função principal
int main(void) {
   ListaEstudantes lista;
   int opcao;
   char nome[TAM_NOME];
   float nota;

   setlocale(LC_ALL, "PT");

   inicializarLista(&lista); //Porque estás a passar o endereço da variável lista, assim, a função pode alterar diretamente os campos dela:

   do {
      printf("\n=== MENU ===\n");
      printf("1. Adicionar estudante\n");
      printf("2. Calcular média\n");
      printf("3. Listar estudantes\n");
      printf("0. Sair\n");

      if (!lerInteiro("Opção: ", &opcao)) {
         printf("Entrada inválida. Introduza um número inteiro.\n");
         continue;
      }

      switch (opcao) {
         case 1:
               lerString("Nome: ", nome, sizeof(nome));

               if (!lerFloat("Nota (0 a 20): ", &nota)) {
                  printf("Entrada inválida. Introduza um valor numérico.\n");
                  break;
               }

               // Validação pedida no enunciado
               if (nota < 0.0f || nota > 20.0f) {
                  printf("Nota inválida. A nota deve estar entre 0 e 20.\n");
                  break;
               }

               if (adicionarEstudante(&lista, nome, nota)) {
                  printf("Estudante adicionado com sucesso!\n");
               } else {
                  printf("Erro: não foi possível adicionar o estudante.\n");
               }
               break;

         case 2:
               if (lista.quantidade == 0) {
                  printf("Não existem estudantes para calcular a média.\n");
               } else {
                  printf("Média: %.2f\n", calcularMedia(&lista));//float com 2 decimais
               }
               break;

         case 3:
               listarEstudantes(&lista);
               break;

         case 0:
               printf("A terminar o programa...\n");
               break;

         default:
               printf("Opção inválida.\n");
      }

   } while (opcao != 0);

   libertarLista(&lista);
   return 0;
}

// Inicializa a lista com capacidade inicial
void inicializarLista(ListaEstudantes *lista) {
   lista->dados = (Estudante *)malloc(CAPACIDADE_INICIAL * sizeof(Estudante));
   if (lista->dados == NULL) {
      printf("Erro: falha na alocação inicial de memória.\n");
      exit(1);
   }

   lista->quantidade = 0;
   lista->capacidade = CAPACIDADE_INICIAL;
}

// Liberta a memória usada pela lista
void libertarLista(ListaEstudantes *lista) {
   free(lista->dados);
   lista->dados = NULL;//Boa prática para evitar um ponteiro pendente
   lista->quantidade = 0;
   lista->capacidade = 0;
}

// Aumenta dinamicamente a capacidade quando a lista enche
// Com temp, só atualizas lista->dados se correr bem.
int aumentarCapacidade(ListaEstudantes *lista) {
   int novaCapacidade = lista->capacidade * 2;
   Estudante *temp = (Estudante *)realloc(lista->dados, novaCapacidade * sizeof(Estudante));

   if (temp == NULL) {
      return 0;
   }

   lista->dados = temp;
   lista->capacidade = novaCapacidade;
   return 1;
}

// Limpa o buffer de entrada
void limparBuffer(void) {
   int c;
   while ((c = getchar()) != '\n' && c != EOF) { //o getchar le um char por vez
      // descarta caracteres
   }
}

// Remove o '\n' final lido por fgets ou seja remove o \n que o fgets() normalmente guarda.
void removerNewline(char *str) {
   str[strcspn(str, "\n")] = '\0';
}

// Lê um inteiro com validação
int lerInteiro(const char *mensagem, int *valor) {
   printf("%s", mensagem);

   if (scanf("%d", valor) != 1) {
      limparBuffer();
      return 0;
   }

   limparBuffer();
   return 1;
}

// Lê um float com validação
int lerFloat(const char *mensagem, float *valor) {
   printf("%s", mensagem);

   if (scanf("%f", valor) != 1) {
      limparBuffer();
      return 0;
   }

   limparBuffer();
   return 1;
}

// Lê uma string com segurança, permitindo espaços
void lerString(const char *mensagem, char *destino, int tamanho) {
   printf("%s", mensagem);

   if (fgets(destino, tamanho, stdin) != NULL) {
      removerNewline(destino);
   }
}

// Adiciona um estudante à lista, aumentando a capacidade se necessário
int adicionarEstudante(ListaEstudantes *lista, const char *nome, float nota) {
   if (lista->quantidade == lista->capacidade) {
      if (!aumentarCapacidade(lista)) {
         return 0;
      }
   }

   strncpy(lista->dados[lista->quantidade].nome, nome, TAM_NOME - 1);
   lista->dados[lista->quantidade].nome[TAM_NOME - 1] = '\0';
   lista->dados[lista->quantidade].nota = nota;
   lista->quantidade++;

   return 1;
}

// Calcula a média das notas
float calcularMedia(const ListaEstudantes *lista) {
   float soma = 0.0f;
   int i;

   for (i = 0; i < lista->quantidade; i++) {
      soma += lista->dados[i].nota;
   }

   return soma / lista->quantidade;
}

// Lista todos os estudantes registados
void listarEstudantes(const ListaEstudantes *lista) {
   int i;

   if (lista->quantidade == 0) {
      printf("Nenhum estudante registado.\n");
      return;
   }

   printf("\n=== Lista de Estudantes ===\n");
   for (i = 0; i < lista->quantidade; i++) {
      printf("%d. %s - %.2f\n",
            i + 1,
            lista->dados[i].nome,
            lista->dados[i].nota);
   }
}