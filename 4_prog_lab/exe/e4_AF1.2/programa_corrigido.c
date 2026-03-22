#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> // [CORREÇÃO] Necessário para usar setlocale() e LC_ALL

// Estrutura para armazenar dados de um estudante
typedef struct {
    char nome[50];
    float nota;
} Estudante;

// Variáveis globais
Estudante *estudantes;
int numEstudantes;

// Protótipos das funções
void adicionarEstudante(char *nome, float nota);
float calcularMedia(void);
void listarEstudantes(void);
void libertarMemoria(void);

// Função principal
int main(void) {
    int opcao;
    char nome[50];
    float nota;

    setlocale(LC_ALL, "PT"); // [CORREÇÃO] Agora funciona corretamente com <locale.h>

    numEstudantes = 0;
    estudantes = (Estudante *)malloc(10 * sizeof(Estudante));

    // [CORREÇÃO] Verificação de falha na alocação de memória
    if (estudantes == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    do {
        printf("\n=== MENU ===\n");
        printf("1. Adicionar estudante\n");
        printf("2. Calcular média\n");
        printf("3. Listar estudantes\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao); 

        switch (opcao) {
            case 1:
                printf("Nome: ");
                scanf("%49s", nome); 
                // [CORREÇÃO] Limite de leitura para evitar overflow do buffer (antes era "%s")

                printf("Nota: ");
                scanf("%f", &nota); 
                // [CORREÇÃO] Corrigido erro de sintaxe (faltava vírgula no scanf)

                adicionarEstudante(nome, nota);
                break;

            case 2:
                // [CORREÇÃO] Evita divisão por zero ao calcular média sem estudantes
                if (numEstudantes == 0) {
                    printf("Não existem estudantes para calcular a média.\n");
                } else {
                    printf("Média: %.2f\n", calcularMedia());
                }
                break;

            case 3:
                listarEstudantes();
                break;

            case 0:
                printf("A sair do programa...\n");
                break;

            default:
                printf("Opção inválida.\n"); 
                // [CORREÇÃO] Opções inválidas (não existia no código original)
                break;
        }

    } while(opcao != 0);

    libertarMemoria();
    return 0;
}

// Adiciona um estudante à lista
void adicionarEstudante(char *nome, float nota) {
    if (numEstudantes < 10) {
        strcpy(estudantes[numEstudantes].nome, nome);
        estudantes[numEstudantes].nota = nota;
        numEstudantes++;
        printf("Estudante adicionado com sucesso!\n");
    } else {
        printf("Lista cheia!\n");
    }
}

// Calcula a média das notas
float calcularMedia(void) {
    float soma = 0.0f; 
    // [CORREÇÃO] Inicialização da variável (antes não estava inicializada)

    int i;

    for (i = 0; i < numEstudantes; i++) {
        soma = soma + estudantes[i].nota;
    }

    return soma / numEstudantes; 
    // [CORREÇÃO] Protegido contra divisão por zero no main()
}

// Lista todos os estudantes
void listarEstudantes(void) {
    int i;

    if (numEstudantes == 0) {
        printf("Nenhum estudante registado.\n");
        return;
    }

    printf("\n=== Lista de Estudantes ===\n");
    for (i = 0; i < numEstudantes; i++) {
        printf("%d. %s - %.2f\n", i+1, estudantes[i].nome, estudantes[i].nota);
    }
}

// Liberta a memória alocada
void libertarMemoria(void) {
    printf("A libertar memória...\n");

    free(estudantes); 
    // [CORREÇÃO] Libertação da memória alocada com malloc()

    estudantes = NULL; 
    // [BOA PRÁTICA] Evita ponteiro pendente (dangling pointer)
}