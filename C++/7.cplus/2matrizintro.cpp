#include <iostream>
using namespace std;
void exemploMatrizBidimensional() {
    int matriz[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    //acessando elementos de uma matriz
    int valor = matriz [1][2]; //acessa o elemento na segunda linha , terceira coluna
    matriz[0][3]=20; //altera o elemento na primeira linha, quarta coluna para 20

    //percorrendo a matriz com for
    cout<<"Elementos da matriz: "<<endl;
    for(int i=0; i<3; i++) {    //percorre as linhas
        for (int j=0; j<4; j++){    //percorre as colunas
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;    //Quebra de linha apos cada linha da matriz
    }
}

//Funcao para demonstrar matrizes dinamicas 
void exemploMatrizDinamica () {
    int linhas = 3, colunas =4;
    int** matrizDinamica = new int*[linhas]; //cria um array de ponteiros para as linhas

    for (int i=0; i < linhas; i++) {
        matrizDinamica[i] = new int[colunas]; //cada ponteiro aponta para um array de colunas
    }
    //exemplo de uso: preenchendo a matriz dinamica com valores
    for(int i=0; i < linhas; i++) {
        for (int j=0; j < colunas; j++) {
            matrizDinamica[i][j] = (i + 1) * (j + 1); //atribui um valor de exemplo
        }
    }
    //exibe os elementos da matriz dinamica
    cout<<"\nELementos da matriz dinamica: "<<endl;
    for(int i=0; i<linhas; i++) {
        for (int j=0; j<colunas; j++) {
            cout<<matrizDinamica[i][j]<<" ";
        }
        cout<<endl;
    }
    //Libera a memoria alocada
    for (int i=0; i<linhas; i++) {
        delete[] matrizDinamica[i];//libera cada linha
    }
    delete[] matrizDinamica;//libera o array de ponteiro
}

//Funcao para demonstrar matrizes tridimensionais
void exemploMatrizTridimensional() {
    //decleracao e inicializacao de uma matriz tridimensional 2x2x2
    int tritabela[2][2][2] = {{{9,8},{7,6}},{{5,4},{3,2}}};
    //lacos aninhados para percorrer a matriz tridimensional
    cout<<"\nElementos da matriz tridimensional: "<<endl;
    for (int i=0; i<2; i++) { //itera sobre a primeira dimensao
        for (int j=0; j<2; j++) {   //itera sobre a segunda dimensao
            for (int k=0; k<2; k++) {   //itera sobre a terceira dimensao
                cout<<tritabela[i][j][k]<<" "; 
            }
            cout<<endl; //nova linha apos percorrer a 3 dimensao
        }
        cout<<endl; //linha apos percorrer a 2 dimensao
    }
}
int main() {
    exemploMatrizBidimensional();
    exemploMatrizDinamica();
    exemploMatrizTridimensional();

    return 0;
}