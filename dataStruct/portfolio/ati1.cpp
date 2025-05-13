/*
Faça um programa na linguagem C/C++ que declare três variáveis do tipo inteiro, denominadas n1, n2 e result, e dois ponteiros de inteiros, denominados p1 e p2. A seguir, faça com que o ponteiro p1 aponte para a variável n1 e o ponteiro p2 aponte para a variável n2. Faça a leitura de dois valores inteiros armazenando-os nas variáveis n1 e n2. Após isso, calcule a soma dos valores das variáveis apenas por meio do uso dos ponteiros, guarde o resultado da soma na variável result e mostre-o na tela.
int *p1, *p2; declara dois ponteiros para inteiros.

p1 = &n1; e p2 = &n2; fazem com que os ponteiros apontem para n1 e n2.

cin >> *p1; lê diretamente no local apontado por p1, ou seja, escreve em n1.

result = *p1 + *p2; realiza a soma usando apenas os ponteiros.

cout exibe o resultado na tela.
*/
#include <iostream>
using namespace std;

int main() {
    int n1, n2, result;   // Variáveis inteiras
    int *p1, *p2;         // Ponteiros para inteiros

    // Ponteiros apontando para as variáveis n1 e n2
    p1 = &n1;
    p2 = &n2;

    // Leitura dos valores usando os ponteiros
    cout << "Digite o primeiro número inteiro: ";
    cin >> *p1;

    cout << "Digite o segundo número inteiro: ";
    cin >> *p2;

    // Soma dos valores apontados pelos ponteiros
    result = *p1 + *p2;

    // Exibe o resultado
    cout << "A soma de " << *p1 << " e " << *p2 << " é: " << result << endl;

    return 0;
}