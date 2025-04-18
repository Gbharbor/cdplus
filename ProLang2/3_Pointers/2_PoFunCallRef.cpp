// ---------------------------------------------
// 2. Ponteiros em Funções: Chamada por Referência
// ---------------------------------------------

// Podemos criar funções que recebem parâmetros de duas formas:

// - Por valor: A função recebe uma cópia do valor da variável. 
//   Qualquer alteração feita dentro da função NÃO afeta o valor original.

// - Por referência: A função recebe o endereço da variável, ou seja, 
//   ela pode alterar diretamente o valor original da variável.
//   Isso é feito com o uso de ponteiros.

// >>> IMPORTANTE: Ao passar por referência com ponteiros, a função pode
// alterar diretamente os valores originais, então deve-se tomar cuidado.

// Exemplo de função com passagem por referência usando ponteiros:
// void soma(int *valor1, int *valor2) { ... }

// Lembre-se:
// ponteiro = endereço da variável
// *ponteiro = valor armazenado no endereço apontado pelo ponteiro

#include <iostream>
using namespace std;

// Função que calcula a potência de um número, alterando o valor original
void potencia(int *numero, int elevado) {
    int valorOriginal = *numero; // Salva o valor original antes de modificações

    // Caso o expoente seja zero, qualquer número elevado a 0 é 1
    if (elevado == 0) {
        *numero = 1;
        return;
    }

    // Multiplica o valor original por ele mesmo (elevado - 1) vezes
    for (int i = 2; i <= elevado; i++) {
        *numero = *numero * valorOriginal;
    }
}

int main() {
    int valor = 9;

    // Como a função espera um ponteiro, passamos o endereço de 'valor' com o operador &
    potencia(&valor, 0);

    // Imprime o resultado da operação (valor pode ter sido alterado pela função)
    cout << "Resultado da potencia: " << valor << endl;

    return 0;
}

// ---------------------------------------------
// 2.1 Ponteiros para Vetores e Matrizes
// ---------------------------------------------

// Ponteiros podem ser usados para acessar e manipular elementos de vetores e matrizes.

// DEFINIÇÃO:
// Um ponteiro pode referenciar diretamente os elementos de um vetor ou matriz, 
// começando pelo primeiro elemento.

// PASSAGEM DE PARÂMETROS:
// Quando passamos um vetor para uma função, na verdade estamos passando o endereço 
// do seu primeiro elemento. Isso permite modificar o vetor original dentro da função.

// ARITMÉTICA DE PONTEIROS:
// - Incrementar um ponteiro move ele para o próximo elemento, de acordo com o tipo de dado.
//   Ex: para int (4 bytes), ponteiro++ move 4 bytes na memória.
// - O compilador cuida do cálculo de deslocamento corretamente.
// - Isso permite acessar os elementos de forma sequencial, como se fosse com índices,
//   mas usando apenas o ponteiro.

// BENEFÍCIOS:
// - Maior controle sobre a manipulação dos dados.
// - Uso mais eficiente da memória.
// - Facilita a passagem de vetores e matrizes para funções sem cópia de dados.

// EXEMPLO:
#include <iostream>
using namespace std;

int main() {
    int vetor[5] = {20, 34, 58, 70, 125};   // Vetor com 5 elementos
    int* ponteiro = vetor;                  // Ponteiro aponta para o primeiro elemento do vetor

    cout << "[Exemplo 2.1] Ponteiros para Vetores\n";

    // Acessa o primeiro elemento
    cout << *ponteiro << endl;

    // Move para o segundo elemento
    ponteiro++;
    cout << *ponteiro << endl;

    // Continua acessando os elementos restantes usando aritmética de ponteiros
    for (int i = 2; i < 5; i++) {
        ponteiro++;
        cout << *ponteiro << endl;
    }

    return 0;
}
// ---------------------------------------------
// 2.2 Ordenação de Vetores: Vetor vs Ponteiro
// ---------------------------------------------

#include <iostream>
using namespace std;

// Ordena um vetor passado como parâmetro (por valor, usando vetor comum)
void ordenarVetorComum(int v[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

// Ordena um vetor usando ponteiro
void ordenarComPonteiro(int* p, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (*(p + j) > *(p + j + 1)) {
                int temp = *(p + j);
                *(p + j) = *(p + j + 1);
                *(p + j + 1) = temp;
            }
        }
    }
}

// Função auxiliar para imprimir um vetor
void imprimirVetor(int v[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    int vetor1[5] = {50, 10, 30, 20, 40};
    int vetor2[5] = {50, 10, 30, 20, 40};

    cout << "[Antes da ordenação]\n";
    cout << "Vetor comum: ";
    imprimirVetor(vetor1, 5);
    cout << "Vetor com ponteiro: ";
    imprimirVetor(vetor2, 5);

    ordenarVetorComum(vetor1, 5);
    ordenarComPonteiro(vetor2, 5);

    cout << "\n[Após a ordenação]\n";
    cout << "Vetor comum: ";
    imprimirVetor(vetor1, 5);
    cout << "Vetor com ponteiro: ";
    imprimirVetor(vetor2, 5);

    return 0;
}