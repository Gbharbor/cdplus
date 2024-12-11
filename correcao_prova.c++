// Este programa demonstra conceitos básicos de C++
// Incluindo variáveis, bibliotecas, estruturas de controle e loops

#include <iostream>
#include <string> // Para manipulação de strings
#include <cstdio> // Para funções estilo C como printf e scanf
using namespace std;

int main() {
    // 1. Variáveis
    // Variáveis são usadas para armazenar valores temporários na memória
    int idade = 18; // Inteiro
    float altura = 1.75; // Ponto flutuante
    string nome = "João"; // Texto

    cout << "Exemplo de variáveis:" << endl;
    cout << "Idade: " << idade << endl;
    cout << "Altura: " << altura << endl;
    cout << "Nome: " << nome << endl << endl;

    // 2. Leitura e escrita com cin e cout
    cout << "Digite sua idade: ";
    cin >> idade;
    cout << "Idade digitada: " << idade << endl << endl;

    // 3. Leitura e escrita com scanf e printf
    printf("Digite sua altura: ");
    scanf("%f", &altura);
    printf("Altura digitada: %.2f\n\n", altura);

    // 4. Controle de loops
    cout << "Exemplo de loop infinito (interrompido por break):" << endl;
    int i = 1;
    while (i > 0) {
        cout << "Valor de i: " << i << endl;
        if (i == 5) break; // Sai do loop
        i++;
    }
    cout << endl;

    // 5. Diferença entre while e do-while
    cout << "Usando while:" << endl;
    i = 0;
    while (i < 3) {
        cout << i << endl;
        i++;
    }

    cout << "Usando do-while:" << endl;
    i = 0;
    do {
        cout << i << endl;
        i++;
    } while (i < 3);
    cout << endl;

    // 6. Estruturas condicionais
    cout << "Digite sua idade novamente: ";
    cin >> idade;

    if (idade >= 18) {
        cout << "Maior de idade" << endl;
    } else {
        cout << "Menor de idade" << endl;
    }
    cout << endl;

    // 7. Comparação entre números
    int n1, n2, n3;
    cout << "Digite os valores de n1, n2 e n3: ";
    cin >> n1 >> n2 >> n3;

    if (n1 > n2 && n1 > n3) {
        cout << "n1 é o maior: " << n1 << endl;
    } else if (n2 > n1 && n2 > n3) {
        cout << "n2 é o maior: " << n2 << endl;
    } else {
        cout << "n3 é o maior: " << n3 << endl;
    }
    cout << endl;

    // 8. Operador %
    int valor;
    cout << "Digite um número: ";
    cin >> valor;
    cout << "Resto da divisão por 3: " << valor % 3 << endl << endl;

    // 9. Loop com for
    cout << "Exemplo de loop usando for:" << endl;
    for (int j = 0; j < 5; j++) {
        cout << j << endl;
    }
    cout << endl;

    // 10. Vetores
    int vetor[10];
    for (int k = 0; k < 10; k++) {
        vetor[k] = k;
    }
    cout << "O terceiro elemento do vetor é: " << vetor[2] << endl;

    // 11. Trabalhando com strings
    string valor1 = "1", valor2 = "2";
    string valorT = valor1 + valor2;
    cout << "Concatenação de strings: " << valorT << endl;

    // Fim do programa
    return 0;
}