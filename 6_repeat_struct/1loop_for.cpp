//Estrutura de Repeticao For//
/*
O loop `for` usado para executar um bloco de código um número definido de vezes.
Ele possui três partes principais:

1. Inicialização: Executa uma vez, geralmente para declarar e inicializar uma variável de controle.
2. Condição: Avaliada antes de cada repetição; enquanto for `true`, o loop continua.
3. Incremento: Atualiza a variável de controle ao final de cada repetição.

A estrutura básica é:

for (inicialização; condição; incremento) {
    // Código a ser repetido
}

O `for` é ideal para loops de quantidade fixa, centralizando a inicialização, condição e incremento em uma única linha, facilitando controle e leitura do código.
*/

//////EXEMPLO 1 : Repeticao de frase
#include <iostream>
using namespace std;
int main() {
    int controle;  // Declara uma variável inteira chamada 'controle' para controlar o loop

    // Loop 'for' que inicia a variável 'controle' em 0 e continua até que 'controle' seja maior que 30
    for (controle = 0; controle <= 30; controle++) {
        // Exibe a mensagem "Esta frase se repetirá até que a variável controle seja maior do que 30"
        cout << "Esta frase se repetirá até que a variável controle seja maior do que 30\n";
        
        // Exibe o valor atual da variável 'controle'
        cout << "controle = " << controle << "\n";
    }

    // Pausa o programa para que o usuário possa ver a saída antes de o programa fechar
    // Esse comando funciona no Windows. Em sistemas Linux ou macOS, você pode comentá-lo.
    system("PAUSE > null");

    return 0;  // Retorna 0 para indicar que o programa terminou sem erros
}

//////EXEMPLO 2 : Incremento e decremento
#include <iostream>
using namespace std;

int main() {
    // Exemplo de incremento: Conta de 1 a 5
    cout << "Contando de 1 a 5:" << endl;
    for (int i = 1; i <= 5; i++) {
        cout << "i = " << i << endl;  // i aumenta em 1 a cada iteração
    }

    cout << endl; // Linha em branco para separar os exemplos

    // Exemplo de decremento: Conta de 5 a 1
    cout << "Contando de 5 a 1:" << endl;
    for (int j = 5; j >= 1; j--) {
        cout << "j = " << j << endl;  // j diminui em 1 a cada iteração
    }

    return 0;
}

//////EXEMPLO 3 : Somar numeros de 1 a 10
#include <iostream>
using namespace std;
int main () {
    int soma =0;
    for(int i=1; i<=10; i++) {
        soma += i; //add o valor de i a variavel soma. e o msm q soma = soma + i
    }
    cout <<"A soma dos numeros de a 10 é: " << soma << endl;
    return 0;
}
//A soma dos números de 1 a 10 é: 55

//////EXEMPLO 4: Imprimir apenas numeros pares entr 1 e 10
#include <iostream>
using namespace std;
int main () {
    cout <<"numeros pares de 1 a 10: " <<endl;
    for (int i = 2; i <=10; i=+2) {
        cout << i << " "; //Imprime o valor de i (apenas pares)
    }
    cout << endl;
    return 0;
}
//Números pares de 1 a 10: 2 4 6 8 10

//////EXEMPLO 5: Multiplicaca de cada numero por 2 (tabela de multiplicacao)
#include <iostream>
using namespace std;
int main () {
    cout << "tabela de multiplicacao por 2: " << endl;
    for (int i = 1; i <=5; i++) {
        cout << i << " x 2 = " << i * 2 << endl; //calcula e exibe a multiplicaco
        return 0;
    }
}
/*
Tabela de multiplicação por 2:
1 x 2 = 2
2 x 2 = 4
3 x 2 = 6
4 x 2 = 8
5 x 2 = 10
*/

//////EXEMPLO 6 : Imprimir a sequencia de Fibonacci (primeiros 10 termos)
#include <iostream>
using namespace std;
int main () {
    int a = 0, b = 1, next;
    cout << "Sequencia de fibonacci (primeiros 10 termos): " <<endl;
    cout << a << " " << b << " "; // 1 e 2 termo ja estao aqui impressos, por isso i comeca em 3

    for (int i = 3; i <= 10; i++) { //comeca em 3, pq os 2 primeiros termos da sequencia 0 e 1 ja foram impressas antes do loop.
        next = a + b; //calcule o proximo termo da sequencia
        cout << next << " ";
        a = b;   //atualiza os valores para o proximo calculo
        b = next; 
    }
    cout << endl;
    return 0;
}
/*
Sequência de Fibonacci (primeiros 10 termos):
0 1 1 2 3 5 8 13 21 34
*/