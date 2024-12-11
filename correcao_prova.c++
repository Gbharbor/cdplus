- qual funcao das variaveis.
- qual a finalidade das bibliotecas.
- complete as lacunas do codigo:

#include<___________> <stdio.h>
int main(){
______ idade; int (por ser um nuemro inteiro)
printf("Entre com a idade");
scanf("%____", &idade); (%d ) para ler inteiros
return 0;
}
- %f ->  float 
- %g -> alterna entre notacao fixa e cientifica, dependendo do valor 
- %e -> notacao cientifica 
- funcao de um compilador? 
um software que traduz codigo fonte escrito em uma linguagem de programacao para codigo de maquina
o compilador converte codigo fonte para linguagem de maquina, permitindo que o programa seja executado diretamente pelo computador.
#include<___________>  // <iostream> // biblio padrao para entrada e saida em C++ 
using ________ std; // namespace std , para usar o cout e cin sem precisar dos :: 
int main(){
______ idade; // int declaracao de um inteiro
cout<<"Entre com a idade";
cin>> ______; // le o valor q o usuario mandar e armazena na variavel idade que e um inteiro
cout<<idade;
return 0;
}


- o codigo entrara em um loop infinito pq o valor de i nunca chegara a zero., podemos criar uma condicao dentro que quando i chega a 10 por exemplo, interrempo.
 int main(){
  int i = 1;
  while (i > 0) {
    i++;
  }
}

corrigido : 
int main () {
    int i = 1;
    while (i > 0) {
        printf("valor de i: ", i)
        if (i == 10) {
            break;
        }
        i++ 
    }
    printf("loop finalizado valor final de i: ", i)
    return 0;
}

Unsigned -> remova a possibilidade de numeros negativos

- um programa c ou c++ deve possuir uma certa estrutura para ser valido, basicamente tem 3 blocos distintos nos programas. a sequencia correta desses blocos é 
bibliotecas , funcoes do usuario , funcao main.
bibliotecas , funcoes do usuario e main 
 a estrutura geral de um programa c ou c++ comeca coma inclusao de biblitoecas segue com a funcao definidas pelo usuario e termina com a execucao da funcao main .
 - sabemos q para impirmir usamos o \t chamado tubulacao, e para que serve isso ? . a sequencia de escape \t insere uma tubulacao horizontal no texto exibido deslocando o conteudo para a proxima parada, de tubulacao.

 - considere a leitura de 3 numeros n1, n2, n3 ; escreva uma estrutura de validacao na linguagem C++ e apresente o maior dentre eles.
 #include <iostream>
 using namespace std;
 int main () {
    int n1, n2, n3;
    cout << "digite os valores de n1, n2, n3"
    cin >> n1 >> n2 >> n3
    
    if ((n1>n2) && (n1 > n3)) {
        cout << "n1 e o maior! "<< n1 <<endl;
    } else if ((n2>n1) && (n2 > n3)) { 
        cout<< "n2 e maior! "<<n2<< endl;
    } else {
        cout <<"n3 e o maior! "<<n3 <<endl;
    }
    return 0;
 }

 - quanto aos lacos de repeticao oq difere wjile do do while,
 o laco while basicamente diz pro codiugo continuar a execucao enquanto a condicao for verdadeira ja o do while primeiro executa e depois verifica a condicao.
 a diferenca fundamente e q o do while executa o bloco ao menos uma vez, mesmo que a condiucao seja falsa, enquanto o while veririfcxa a condicao antes de executar o bloco.
 =
 - a condicao verdadeira ou falsa e chamada de condicao logica. 

 - sobre AS ESTRUTURAS D CONDICIONAIS OU DECISao : 
if ,  tesata a condicao expressa entre aprenteses e caso a condicao seja vdd, os comandos declarados entre as chaves serao executados.
else,  e opcional e somen te e executada se a validacao do if for falsa.

- int main() {
  string valor = "1"; //string
  string valor1 = "2"; //string
  valor = valor + valor1;
  cout << valor;
  return 0; //vai impirmir : 12 pq estamos concatenando 2 strings
}
