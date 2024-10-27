//LOOP WHILE
/* 
- Estrutura de repetição que executa um bloco de código enquanto uma condição especificada for verdadeira.
- O loop `while` é útil quando o número de iterações não é conhecido de antemão e depende de uma condição.
- Certifique-se de que a condição eventualmente se torne falsa para evitar loops infinitos.

Como Funciona:
1. Avaliação da Condição: Antes de cada iteração, a condição é avaliada. Se for verdadeira (`true`), o bloco de código dentro do loop é executado.
2. Execução do Código: O código dentro do loop é executado.
3. Reavaliação da Condição: Após a execução do código, a condição é verificada novamente. Se ainda for verdadeira, o loop se repete. Se for falsa (`false`), o loop termina.
*/

//EXEMPLO 1 
#include <iostream>  // Inclui a biblioteca iostream para operações de entrada e saída
using namespace std;

int main() {
    int i = 1;  // Inicializa a variável de controle i em 1

    // O loop while continuará executando enquanto a condição (i <= 5) for verdadeira
    while (i <= 5) {
        cout << "i = " << i << endl;  // Imprime o valor atual de i
        i++;  // Incrementa i em 1 a cada iteração
    }

    return 0;  // Retorna 0 para indicar que o programa terminou sem erros
}
/*
Contando de 1 a 5:
i = 1
i = 2
i = 3
i = 4
i = 5
*/
//EXEMPLO 2 : SOMAR NUMEROS ATE UM LIMITE
#include <iostream>
using namespace std;

int main() {
    int numero, soma = 0;  // Inicializa a variável para o número e a soma

    cout << "Digite números para somar (digite 0 para parar):" << endl;

    // O loop continua até que o usuário digite 0
    while (true) {
        cin >> numero;  // Lê um número do usuário
        if (numero == 0) {  // Se o número for 0, o loop termina
            break;
        }
        soma += numero;  // Adiciona o número à soma total
    }

    cout << "A soma total é: " << soma << endl;  // Exibe a soma total

    return 0;
}
/*
Digite números para somar (digite 0 para parar):
5
3
7
0
A soma total é: 15
*/

//EXEMPLO 3 : JOGO DE ADIVINHACAO
#include <iostream>
#include <cstdlib> // Para rand() e srand()
#include <ctime>   // Para time()
using namespace std;

int main() {
    srand(time(0));  // Inicializa o gerador de números aleatórios
    int numeroSecreto = rand() % 100 + 1;  // Gera um número secreto entre 1 e 100
    int palpite = 0;  // Inicializa o palpite do usuário

    cout << "Adivinhe o número secreto entre 1 e 100:" << endl;

    // O loop continua enquanto o palpite for diferente do número secreto
    while (palpite != numeroSecreto) {
        cout << "Digite seu palpite: ";
        cin >> palpite;  // Lê o palpite do usuário

        if (palpite < numeroSecreto) {
            cout << "Muito baixo! Tente novamente." << endl;  // Dica para palpite baixo
        } else if (palpite > numeroSecreto) {
            cout << "Muito alto! Tente novamente." << endl;  // Dica para palpite alto
        } else {
            cout << "Parabéns! Você adivinhou o número!" << endl;  // Acertou
        }
    }

    return 0;
}
/*
Adivinhe o número secreto entre 1 e 100:
Digite seu palpite: 50
Muito baixo! Tente novamente.
Digite seu palpite: 75
Muito alto! Tente novamente.
Digite seu palpite: 60
Parabéns! Você adivinhou o número!
*/

//EXEMPLO 4 : CONTAGEM REGRESSIVA PARA O ANO NOVO
#include <iostream>
using namespace std;

int main() {
    int contagem = 10;  // Inicializa a contagem em 10

    cout << "Contagem regressiva para o Ano Novo!" << endl;

    // O loop continua enquanto a contagem for maior que 0
    while (contagem > 0) {
        cout << contagem << endl;  // Imprime o valor atual da contagem
        contagem--;  // Decrementa a contagem em 1
    }

    cout << "Feliz Ano Novo!" << endl;  // Mensagem após a contagem regressiva

    return 0;
}
/*
Contagem regressiva para o Ano Novo!
10
9
8
7
6
5
4
3
2
1
Feliz Ano Novo!
*/