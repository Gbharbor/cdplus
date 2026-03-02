#include <iostream>
using namespace std;
int somaVetor(int *vetor, int n) {
   int soma = 0;
   int *apt = vetor;
   int *apt_fim = vetor + n;

   for(; apt < apt_fim; apt++) {
      soma += *apt;
   }
   return soma;
}

void exibeMat(int mat[3][3], int linhas, int colunas) {
   int *apt, *inicio, *fim;
   inicio = &mat[0][0];
   fim = inicio + (linhas * colunas);

   for(apt = inicio, apt < fim; apt++;) {
      cout<<*apt<<" ";
   }
   cout<<endl;
}
int main() {
   //1- usando ponteiro com vetor
   int vetor[5] = {10,20,30,40,50};
   int *apt_vetor = vetor; //aponta p/ o primeiro elemento
   cout<<"primeiro elemento do vetor: "<<*apt_vetor<<endl;
   //acessando posicao especifica com o &vetor[i]
   int *apt_vetor2 = &vetor[2];
   cout<<"elemento da posicao 2: "<<*apt_vetor2<<endl;
   //aritmetica c/ vetores
   cout<<"elementos na posicao 3 (c/ponteiros): "<<*(vetor + 3)<<endl;

   //2- soma dos elementos c/ ponteiros
   int resultado = somaVetor(vetor, 5);
   cout<<"soma dos elementos do vetor: "<<resultado<<endl;

   //3- ponteiro p/ matriz
   int matriz[3][3] = {
      {1,2,3},
      {4,5,6},
      {7,8,9}
   };
   cout<<"elementos da matriz(usando ponteiros)";
   exibeMat(matriz, 3, 3);

   //4- alocacao dinamica de vetor
   double *valores = new double[3];
   valores[0] = 1.1;
   valores[1] = 2.2;
   valores[2] = 3.3;
   cout<<"vetor alocado dinamicamente: ";
   for (int i = 0; i < 3; i++) {
      cout<<valores[i]<<" ";
   }
   cout<<endl;
   delete[] valores; //deslocando memoria
   
   //5- ponteiro para ponteiro
   int numero = 100;
   int *apt = &numero;
   int **apt_duplo = &apt;

   cout<<"endereco de apt_duplo: "<<&apt_duplo<<endl;
   cout<<"conteudo de apt_duplo(endereco de apt): "<<apt_duplo<<endl;
   cout<<"conteudo de *apt_duplo(endereco de numero): "<<*apt_duplo<<endl;
   cout<<"conteudo de **apt_duplo(valor de numero): "<<**apt_duplo<<endl;
   return 0;
}