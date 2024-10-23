/*EXEMPLO DE OUTPUT PRINTF: usando variavel %d (valores inteiros)*/

#include <stdio.h> //aqui inclui a biblioteca standard input output da linguagem C, inclusive a funcao printf vem dessa biblioteca.
#include <stdlib.h> //ja aqui inclui a standard library do C, desde alocacao de memoria, controle de processos, conversao numerica, etc.

int main() { //int main define a funcao principal do programa , em C o ponto de entrada de qualquer programa é a main().
    int numero1; //aqui declaramos uma variavel inteira chamada numero1
    numero1 = 21; //aqui demos valor a variavel inteira numero1
        printf("o valor do numero é: %d\n", numero1); //aqui esta o printf que serve para imprimir textos e variaveis na tela.
        //porem o %d nao e mostrado pq ele so serve para dizer que estamos a espera de um numero inteiro, que é o 21 
        return 0;// aqui e para dizer q a funcao main esta terminando e retornando 0 para o sistema operacional, em C significa que o programa foi concluido com sucesso.
}; // em C n e necessario usar o ponto e virgula