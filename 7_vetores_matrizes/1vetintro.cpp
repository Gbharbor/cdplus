/*
## Vetores (ou Arrays) em Programação

Vetores, também conhecidos como **arrays**, são estruturas de dados que armazenam múltiplos valores de um mesmo tipo em uma única variável. Eles são úteis para organizar e manipular conjuntos de dados, como listas de notas, nomes de alunos, etc.

Imagine que precisamos criar um sistema de notas para uma escola, onde cada aluno tem uma nota registrada. Em vez de criar uma variável para cada nota, podemos utilizar um vetor para armazenar todas as notas em uma única estrutura.

### Declarando um Vetor

Para criar um vetor, é necessário especificar três atributos principais:
1. **O tipo de valor** que será armazenado no vetor (ex.: `int` para inteiros, `float` para números com casas decimais, `char` para caracteres).
2. **O nome do vetor**, que será utilizado para acessá-lo.
3. **O número de elementos** do vetor, que representa quantas posições ele terá.

#### Sintaxe Geral
```cpp
<tipo> <nome_do_vetor>[<número_de_elementos>];
```

#### Exemplos
1. Para criar um vetor de inteiros para armazenar notas de 5 alunos:
 
   int notas[5];

2. Um vetor de caracteres (letras) para armazenar as iniciais dos nomes de 10 alunos:

   char iniciais[10];

3. Um vetor de números com ponto flutuante (float) para armazenar as médias de 3 turmas:

   float medias[3];

### Exemplo de Cálculo de Memória Ocupada

A quantidade de memória que um vetor ocupa depende do tipo dos valores armazenados e do número de elementos. Por exemplo:

- Um vetor de **100 elementos do tipo `int`** (inteiro, que em geral ocupa 2 bytes em C++) requer:

  100 * 2 = 200 bytes de memória

- Um vetor de **100 elementos do tipo `float`** (ponto flutuante, geralmente ocupa 4 bytes em C++) requer:

  100 * 4 = 400 bytes de memória

### Inicialização de Vetores
Em C++, ao declarar um vetor e atribuir valores apenas a alguns elementos, os elementos restantes são automaticamente inicializados com zero. Por exemplo:

int numeros[5] = {0};  // Inicializa todos os 5 elementos com zero

### Acessando Elementos de um Vetor
Para acessar os elementos de um vetor, usamos índices, que representam a posição de cada elemento. **Os índices começam em 0**, então o primeiro elemento está na posição 0, o segundo na posição 1, e assim por diante.
Exemplo:

int notas[5] = {7, 8, 9, 10, 6};
cout << notas[0];  // Saída: 7 (primeiro elemento)
cout << notas[4];  // Saída: 6 (último elemento)

### Utilizando Laços para Percorrer Vetores
Para percorrer e acessar todos os elementos de um vetor, geralmente usamos um laço `for`, que itera de 0 até o número de elementos menos 1.
Exemplo:

int notas[5] = {7, 8, 9, 10, 6};
// Exibindo todas as notas
for (int i = 0; i < 5; i++) {
    cout << "Nota " << i + 1 << ": " << notas[i] << endl;
}

### Definindo Constantes para o Tamanho de Vetores
Usar uma constante para definir o tamanho de um vetor torna o código mais flexível. Em vez de alterar manualmente o tamanho do vetor em vários locais do código, basta alterar o valor da constante.
Exemplo:

const int NUM_ALUNOS = 5;
int notas[NUM_ALUNOS];

Dessa forma, se o número de alunos mudar, basta alterar o valor de `NUM_ALUNOS`, sem precisar modificar o código em vários pontos.
*/
#include <stdio.h>

int main() {
    int vetor[5];  // Declara um vetor de 5 inteiros

    // Atribuindo valores
    vetor[0] = 10;
    vetor[1] = 20;
    vetor[2] = 30;
    vetor[3] = 40;
    vetor[4] = 50;

    // Acessando e imprimindo os valores
    for (int i = 0; i < 5; i++) {
        printf("Elemento %d: %d\n", i, vetor[i]);
    }

    return 0;
}

//EXEMPLO ACESSANDO OS ELEMENTOS DE UM VETOR OU MATRIZ

#include <iostream>
using namespace std;

int main() {
    int matriz[5] = {1, 2, 3, 4, 5};

    cout << "O primeiro valor da matriz é: " << matriz[0] << endl;
    cout << "O último valor da matriz é: " << matriz[4] << endl;
    cout << "Somando o segundo e o quarto elementos da matriz temos: " << matriz[1] + matriz[3] << endl;

    // Alterando o valor do terceiro elemento da matriz
    matriz[2] = 27;
    cout << "Mudamos o valor do terceiro elemento da matriz para: " << matriz[2] << endl;

    // Pausa o sistema para visualização no Windows
    system("pause > null");

    return 0;
}

//EXEMPLO USANDO LACOS PARA PERCORRER OS VETORES
#include <iostream>
using namespace std;

int main() {
    int sequencia[4];

    // Lê os elementos do vetor a partir da entrada do usuário
    for (int i = 0; i < 4; i++) {
        cout << "Entre com o elemento número " << (i + 1) << " da sequência: ";
        cin >> sequencia[i];
    }

    // Exibe a sequência de elementos inseridos
    cout << "A sequência entrada pelo usuário foi: ";
    for (int i = 0; i < 4; i++) {
        cout << sequencia[i] << " ";
    }
    cout << endl;

    // Pausa o programa no Windows para visualização
    system("pause > null");

    return 0;
}

//EXEMPLO USANDO CONSTANTES
#include <iostream>
using namespace std;

int main() {
    const int TAMANHO = 4;       // Define uma constante para o tamanho do array
    int sequencia[TAMANHO];      // Declara o array com tamanho fixo usando a constante

    // Lê os elementos do array a partir da entrada do usuário
    for (int i = 0; i < TAMANHO; i++) {
        cout << "Entre com o elemento número " << (i + 1) << " da sequência: ";
        cin >> sequencia[i];
    }

    // Exibe a sequência de elementos inseridos
    cout << "A sequência entrada pelo usuário foi: ";
    for (int i = 0; i < TAMANHO; i++) {
        cout << sequencia[i] << " ";
    }
    cout << endl;

    // Pausa o programa no Windows para visualização
    system("pause > null");

    return 0;
}