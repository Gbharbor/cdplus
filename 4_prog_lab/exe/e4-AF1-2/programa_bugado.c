#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar dados de um estudante
typedef struct {
    char nome[50];
    float nota;
} Estudante;

// Variáveis globais
Estudante* estudantes; //bug 3
int numEstudantes;

// Protótipos das funções
void adicionarEstudante(char* nome, float nota);
float calcularMedia();
void listarEstudantes();
void libertarMemoria();

// Função principal
int main(void) {
    int opcao;
    char nome[50];
    float nota;
    setlocale(LC_ALL, "PT"); //bug 1
    numEstudantes = 0;
    estudantes = (Estudante*)malloc(10 * sizeof(Estudante)); //bug 2
    
    do {
        printf("\n=== MENU ===\n");
        printf("1. Adicionar estudante\n");
        printf("2. Calcular média\n");
        printf("3. Listar estudantes\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao); //bug 9
        
        switch(opcao) { //bug 10
            case 1:
                printf("Nome: ");
                scanf("%s", nome); //bug 4
                printf("Nota: ");
                scanf("%f" &nota); // bug 5
                adicionarEstudante(nome, nota);
                break;
            case 2:
                printf("Média: %.2f\n", calcularMedia());
                break;
            case 3:
                listarEstudantes();
                break;
        }
    } while(opcao != 0);
    
    libertarMemoria();
    return 0;
}

// Adiciona um estudante à lista
void adicionarEstudante(char* nome, float nota) {
    if(numEstudantes < 10) {
        strcpy(estudantes[numEstudantes].nome, nome);
        estudantes[numEstudantes].nota = nota;
        numEstudantes++;
        printf("Estudante adicionado com sucesso!\n");
    } else {
        printf("Lista cheia!\n");
    }
}

// Calcula a média das notas
float calcularMedia() {
    float soma; //bug 6
    int i;
    
    for(i = 0; i < numEstudantes; i++) {
        soma = soma + estudantes[i].nota;
    }    
    return soma / numEstudantes; //bug 7
}

// Lista todos os estudantes
void listarEstudantes() {
    int i;
    
    if(numEstudantes == 0) {
        printf("Nenhum estudante registado.\n");
        return;
    }
    
    printf("\n=== Lista de Estudantes ===\n");
    for(i = 0; i < numEstudantes; i++) {
        printf("%d. %s - %.2f\n", i+1, estudantes[i].nome, estudantes[i].nota);
    }
}

// Liberta a memória alocada
void libertarMemoria() { //bug 8
    printf("A libertar memória...\n");
    // (código de libertação omitido pelo programador original)
}