#include <iostream>
#include <string>
using namespace std;

//definindo uma struct para representar uma pessoa
struct Pessoa {
   string nome; //nome da pessoa
   int idade; //idade da pessoa
   float altura; //altura da pessoa

   //metodo para exibir informacoes da pessoa
   void exibirInfo() {
      cout<<"Nome: "<<nome<<", idade: "<<idade<<endl;
   }
};
// 1.Tipo struct em C++
//Em c++, assim como em C uma struct define um novo tipo de dado, isso significa que , apos declarar uma struct , voce pode criar variaveis desse tipo e usalas como qualquer outro tipo de dado. A diferenca em c++ e que, alem de armazenar dados, uma struct pode ter metodos, construtores e outros recursos tipicos da programacao orientada a objetos.
void exemploStruct() {
   //declarando variaveis do tipo Pessoa
   Pessoa p1, p2;
   //inicializando as varaiveis
   p1.nome = "Ana";
   p1.idade = 25;

   p2.nome = "Mari";
   p2.idade = 12;
   
   //exibindo as informacoes das varaiveis
   p1.exibirInfo();
   p2.exibirInfo();
}
// 2.Como escrever e ler elementos de uma struct em C++
//assim como em C, para acessar e modificar os membros de uma struct, usamos operador ponto, a principal diferenca de C++ é que utilizamos o cin e cout para entrada e saida de dados.
void exemploLeituraEscrita() {
   //copiando a variavel do tipo pessoa
   Pessoa p1;
   //escrevendo os dados na struct
   cout<<"digite o nome: ";
   getline(cin, p1.nome); //usamos getline para ler o nome com espacos

   cout<<"digite a idade: ";
   cin>>p1.idade;

   cout<<"digite a altura: ";
   cin>>p1.altura;

   //Lendo e exibindo os dados da struct
   cout<<"Nome: "<<p1.nome<<endl;
   cout<<"Idade: "<<p1.idade<<endl;
   cout<<"Altura: "<<p1.altura<<endl; 
};
// 3.Como declarar tipos com typedef em C++
//em c e c++, o typedef e usado para criar um nome alternativo, para um tipo de dado, facilitando o codigo e evitando repeticoes. No caso de structs, isso e util para evitar a necessidade de escrever struct sempre que voce quiser declrar uma variavel tipo.
void exemploTypedef() {
   typedef struct Pessoa{
      string nome;
      int idade;
      float altura;
   } Pessoa;
   
   //declarando uma variavel do tipo Pessoa
   Pessoa p1;

   //inicializando a struct
   p1.nome = "mariana";
   p1.idade = 13;
   p1.altura = 1.55;

   //Exibir os dados da pessoa
   cout<<"Nome: "<<p1.nome<<endl;
   cout<<"Idade: "<<p1.idade<<endl;
   cout<<"Altura: "<<p1.altura<<"metros"<<endl;  
}

//Alternativa em C++ usando "using" para criar alias.
void exemploUsing() {
   //Definindo uma struct com using
   struct Pessoa {
      string nome;
      int idade;
      float altura;
   };
   //criando um alias para a struct pessoa
   using PessoaAlias = Pessoa;

   //declarando uma variavel do tipo PessoaAliar
   PessoaAlias p1;
   
   //Inicializando a struct
   p1.nome = "Ana";
   p1.idade = 30;
   p1.altura = 1.60;

   //exibindo os dados da pessoa
   cout<<"Nome: "<<p1.nome<<endl;
   cout<<"Idade: "<<p1.idade<<endl;
   cout<<"Altura: "<<p1.altura<<"metros"<<endl;
}
// 4.Como enviar uma struct para uma funcao em C++
// Em C++, assim como em C, podemos passar uma struct para uma funcao de duas formas:
// Por Valor : Faz uma copia da struct e , portanto, qualquer modificacao na funcao nao afeta o original
// Por Referencia : Passa o endereco da struct, permitindo que a funcao modifique diretamente o conteudo da struct.
void imprimirPessoa(Pessoa p) {
   cout<<"Nome: "<<p.nome<<"- idade "<<p.idade<<endl;
}
//funcao que recebe a struct por referencia (modifica os dados diretamente)
void atualizarIdade(Pessoa& p) {
   p.idade +=1; //incrementa a idade
}
void exemploPassagemStruct() {
   //Criando a variavel do tipo Pessoa
   Pessoa p1 = {"Marina", 25, 1.54};

   //enviando a struct por valor
   imprimirPessoa(p1); //passa uma copoa de p1 para a funcao

   //enviando a struct por referencia
   atualizarIdade(p1); //passa p1 por referemcoa, entao a idade sera modificada

   //exibindo os dados apos a modificacao
   cout<<"Apos atualizacao"<<endl;
   imprimirPessoa(p1); //mostra a idade atualizada
}

int main() {
   //chamando todas funcoes para demonstrar os exemplos:
    cout << "---- Exemplo de Struct ----" << endl;
    exemploStruct();
    
    cout << "\n---- Exemplo de Leitura e Escrita ----" << endl;
    exemploLeituraEscrita();
    
    cout << "\n---- Exemplo de Typedef ----" << endl;
    exemploTypedef();
    
    cout << "\n---- Exemplo de Using ----" << endl;
    exemploUsing();
    
    cout << "\n---- Exemplo de Passagem de Struct ----" << endl;
    exemploPassagemStruct();

    return 0;
};











