// 1- O que são procedimentos e funções
// Na programação estruturada, existem duas maneiras de modularizar o código:

// 1.1 - Procedimentos
// Um procedimento é um bloco de código que não retorna nenhum valor.
// Ele é declarado com o tipo de retorno 'void' e pode conter vários parâmetros (argumentos).
// Procedimentos são usados para realizar tarefas específicas, mas sem retornar um valor para quem o chamou.

#include <iostream>
using namespace std;

// Procedimento para exibir um menu
void escreveMenu() {
   cout << '\nEscolha uma opção';
   cout << '\nn1 - para cadastrar';
   cout << '\nn2 - para listar';
   cout << '\nn3 - para sair';
}

int main() {
   escreveMenu(); // Chama o procedimento dentro da main. Não é necessário usar 'return' aqui.
   return 0;      // Retorna 0 indicando que o programa terminou com sucesso.
}

// 1.2 - Funções
// Uma função é semelhante a um procedimento, mas sempre retorna um valor.
// A diferença principal é que a função possui um tipo de retorno especificado no início da declaração.
// Pode retornar valores como 'int', 'float', 'double', 'char', entre outros.

#include <iostream>
using namespace std;

// Função para calcular o fatorial de um número
int calculaFatorial(int x) {
    int resultado = 1;
    while (x != 1) {
        resultado *= x;  // Multiplica o resultado pelo valor de x
        x--;             // Decrementa x até que seja igual a 1
    }
    return resultado;  // Retorna o resultado do fatorial
}

int main() {
    int fatorial = calculaFatorial(10);  // Chama a função e armazena o valor retornado
    cout << fatorial << endl;            // Exibe o valor do fatorial
    return 0;                            // Retorna 0 indicando que o programa terminou com sucesso
}