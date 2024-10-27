/* Laços aninhados (ou loops aninhados) em C++ referem-se a ter um loop dentro de outro loop. Essa estrutura permite a execução de um conjunto de instruções múltiplas vezes em relação a cada iteração do loop externo. Isso é especialmente útil para trabalhar com estruturas de dados que possuem múltiplas dimensões, como matrizes (arrays bidimensionais) ou para realizar operações em combinações de dados.

### Estrutura Básica

A estrutura básica de laços aninhados é a seguinte:

```cpp
for (inicialização; condição; incremento) {
    // Código do loop externo

    for (inicialização; condição; incremento) {
        // Código do loop interno
    }
}
```

### Como Funciona

1. **Execução do Loop Externo**: O loop externo começa e sua condição é verificada. Se for verdadeira, o código dentro do loop externo é executado.
2. **Execução do Loop Interno**: Dentro do loop externo, o loop interno é iniciado. A condição do loop interno é verificada, e, se for verdadeira, o código do loop interno é executado.
3. **Repetição**: Após a execução do loop interno, ele retorna para verificar sua condição novamente. Isso se repete até que a condição do loop interno se torne falsa.
4. **Avanço do Loop Externo**: Depois que o loop interno termina, o controle retorna ao loop externo, que avança para a próxima iteração e reavalia sua condição.

### Exemplo Prático

Aqui está um exemplo simples que utiliza laços aninhados para imprimir uma tabela de multiplicação de 1 a 5.

*/
#include <iostream>
using namespace std;

int main() {
    // Laço externo para as linhas (1 a 5)
    for (int i = 1; i <= 5; i++) {
        // Laço interno para as colunas (1 a 5)
        for (int j = 1; j <= 5; j++) {
            cout << i * j << "\t";  // Imprime o produto de i e j
        }
        cout << endl;  // Nova linha após cada linha da tabela
    }

    return 0;
}
/*
### Saída Esperada

```
1	2	3	4	5	
2	4	6	8	10	
3	6	9	12	15	
4	8	12	16	20	
5	10	15	20	25	
```

### Resumo

- **Utilidade**: Laços aninhados são úteis quando você precisa executar um conjunto de instruções para cada elemento de um conjunto maior, como em tabelas ou matrizes.
- **Complexidade**: O número total de iterações em laços aninhados é o produto do número de iterações de cada loop. Portanto, se ambos os laços fazem 5 iterações, o total de iterações será 5 * 5 = 25.
- **Performance**: Laços aninhados podem aumentar a complexidade computacional, por isso é importante utilizá-los com cuidado em algoritmos que possam se tornar ineficientes com um número elevado de iterações.
*/

//EXEMPLO 2 : CRIACAO DE UMA MATRIZ 3X3
#include <iostream>
using namespace std;

int main() {
    int matriz[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Laço externo para as linhas
    for (int i = 0; i < 3; i++) {
        // Laço interno para as colunas
        for (int j = 0; j < 3; j++) {
            cout << matriz[i][j] << "\t";  // Imprime o elemento da matriz
        }
        cout << endl;  // Nova linha após cada linha da matriz
    }

    return 0;
}
/*
1	2	3	
4	5	6	
7	8	9	
*/

//EXEMPLO 3 : TRIANGULO DE PASCAL 
#include <iostream>
using namespace std;

int main() {
    int linhas = 5;  // Número de linhas do triângulo
    int tri[5][5] = {0};  // Inicializa uma matriz para armazenar os valores

    // Preenchendo o triângulo de Pascal
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j <= i; j++) {
            // Cada elemento é a soma dos dois elementos acima
            if (j == 0 || j == i) {
                tri[i][j] = 1;  // As bordas são 1
            } else {
                tri[i][j] = tri[i - 1][j - 1] + tri[i - 1][j];  // Soma dos elementos
            }
        }
    }

    // Imprimindo o triângulo de Pascal
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j <= i; j++) {
            cout << tri[i][j] << " ";  // Imprime o valor do triângulo
        }
        cout << endl;  // Nova linha após cada linha do triângulo
    }

    return 0;
}
/*
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
*/

//EXEMPLO 4 : IMPRESSAO DE UM QUADRADO DE ASTERISCOS
#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Digite o tamanho do quadrado: ";
    cin >> n;  // Lê o tamanho do quadrado

    // Laço externo para as linhas
    for (int i = 0; i < n; i++) {
        // Laço interno para as colunas
        for (int j = 0; j < n; j++) {
            cout << "* ";  // Imprime um asterisco
        }
        cout << endl;  // Nova linha após cada linha do quadrado
    }

    return 0;
}
/*
* * * * 
* * * * 
* * * * 
* * * * 
*/

//EXEMPLO 5 : MULTIPLICACAO DE MATRIZES
#include <iostream>
using namespace std;

int main() {
    int matrizA[2][2] = {{1, 2}, {3, 4}};
    int matrizB[2][2] = {{5, 6}, {7, 8}};
    int resultado[2][2] = {0};  // Inicializa a matriz resultado

    // Multiplicação de matrizes
    for (int i = 0; i < 2; i++) {  // Laço para linhas da matriz A
        for (int j = 0; j < 2; j++) {  // Laço para colunas da matriz B
            for (int k = 0; k < 2; k++) {  // Laço para multiplicação
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];  // Multiplica e acumula
            }
        }
    }

    // Imprimindo a matriz resultado
    cout << "Resultado da multiplicação da matriz A e B:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << resultado[i][j] << "\t";  // Imprime o elemento resultado
        }
        cout << endl;  // Nova linha após cada linha da matriz
    }

    return 0;
}
/*
Resultado da multiplicação da matriz A e B:
19	22	
43	50	
*/