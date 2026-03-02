#include <iostream>
#include <stdio.h>
using namespace std;

void exemploBasicoVetores() {
    int vetor[5]; //vetor com 5 inteiros
    vetor[0] =10;
    vetor[1] =20;
    vetor[2] =30;
    vetor[3] =40;
    vetor[4] =50;
    //acessando e imprimindo os valores do vetor:
    cout<<"valor do vetor: \n";
    for (int i=0; i < 5; i++ ) {
        cout<<"elemento: \n"<< i <<":"<<vetor[i]<<endl;
    }
}

void exemploAcessandoElementos() {
    int matriz[5] = {1, 2, 3, 4, 5};

    cout<<"\nO primeiro valor da matriz é: "<<matriz[0]<<"ultimo valor: "<<matriz[4]<<endl;
    cout<<"somando o segundo e quarto elemento da matriz temos: "<<matriz[1] + matriz[3]<<endl;
    
    //alterar valor da matriz
    matriz[2] = 27;
    cout<<"mudamos o valor do terceiro elemento da matriz para: "<<matriz[2]<<endl;
}
//Funcao para ler e exibir elementos de um vetor:
void exemploLacosParaPercorrerVetores() {
    int sequencia[4];
    //le os elementos do vetor a partir da entrada do usuario
    for(int i=0; i <4; i++) {
        cout<<"entre com o elemento numero:"<<(i+1)<<" da sequencia: ";
        cin>>sequencia[i];
    }
    //exibe a sequencia de elementos inseridos: 
    cout<<"Sequencia entrada pelo usuario foi: ";
    for (int i=0; i<4;i++) {
        cout<<sequencia[i] <<" ";
    }
    cout<<endl;
}
//funcao para usar constantes no tamanho do vetor
void exemploUsandoConstantes() {
    const int TAMANHO =4; //define uma constante para o tam do array
    int sequencia[TAMANHO]; //declara o array com tam fixo usando a constante

    //le os elementos do array a partir da entrada do usuario
    for (int i=0; i < TAMANHO; i++) {
        cout<<"Entre com o elemento numero "<<(i+1)<<"da sequencia";
        cin>>sequencia[i];
    }
    //Exibe a sequencia de elementos inseridos
    cout<<"A sequencia entrada pelo usuario foi: ";
    for(int i=0;i<TAMANHO; i++) {
        cout<<sequencia[i]<<" ";
    }
    cout<<endl;
}
int main () {
    exemploBasicoVetores();
    exemploAcessandoElementos();
    exemploLacosParaPercorrerVetores();
    exemploUsandoConstantes();
    
    return 0;
}