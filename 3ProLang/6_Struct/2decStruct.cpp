#include <iostream>
#include <string>
using namespace std;

// Definindo uma struct para representar uma pessoa
struct Pessoa {
   string nome;    // Nome da pessoa
   int idade;      // Idade da pessoa
   float altura;   // Altura da pessoa

   // Método para exibir informações da pessoa
   void exibirInfo() {
      cout << "Nome: " << nome << ", idade: " << idade << endl;
   }
};

// 1. Tipo struct em C++
// Em C++, assim como em C, uma struct define um novo tipo de dado.
// Isso significa que, após declarar uma struct, você pode criar variáveis desse tipo e usá-las como qualquer outro tipo de dado.
// A diferença em C++ é que, além de armazenar dados, uma struct pode ter métodos, construtores e outros recursos típicos da programação orientada a objetos.
void exemploStruct() {
   // Declarando variáveis do tipo Pessoa
   Pessoa p1, p2;

   // Inicializando as variáveis
   p1.nome = "Ana";
   p1.idade = 25;

   p2.nome = "Mari";
   p2.idade = 12;

   // Exibindo as informações das variáveis
   p1.exibirInfo();
   p2.exibirInfo();
}

// 2. Como escrever e ler elementos de uma struct em C++
// Assim como em C, para acessar e modificar os membros de uma struct, usamos o operador ponto.
// A principal diferença de C++ é que utilizamos o cin e cout para entrada e saída de dados.
void exemploLeituraEscrita() {
   // Criando uma variável do tipo Pessoa
   Pessoa p1;

   // Escrevendo os dados na struct
   cout << "Digite o nome: ";
   getline(cin, p1.nome);  // Usamos getline para ler o nome com espaços

   cout << "Digite a idade: ";
   cin >> p1.idade;

   cout << "Digite a altura: ";
   cin >> p1.altura;

   // Lendo e exibindo os dados da struct
   cout << "Nome: " << p1.nome << endl;
   cout << "Idade: " << p1.idade << endl;
   cout << "Altura: " << p1.altura << endl; 
}

// 3. Como declarar tipos com typedef em C++
// Em C e C++, o typedef é usado para criar um nome alternativo para um tipo de dado.
// Isso facilita o código e evita repetições. No caso de structs, é útil para evitar a necessidade de escrever 'struct' sempre que for declarar uma variável do tipo.
void exemploTypedef() {
   typedef struct Pessoa {
      string nome;
      int idade;
      float altura;
   } Pessoa;
   
   // Declarando uma variável do tipo Pessoa
   Pessoa p1;

   // Inicializando a struct
   p1.nome = "mariana";
   p1.idade = 13;
   p1.altura = 1.55;

   // Exibindo os dados da pessoa
   cout << "Nome: " << p1.nome << endl;
   cout << "Idade: " << p1.idade << endl;
   cout << "Altura: " << p1.altura << " metros" << endl;  
}

// Alternativa em C++ usando "using" para criar alias
void exemploUsing() {
   // Definindo uma struct com using
   struct Pessoa {
      string nome;
      int idade;
      float altura;
   };

   // Criando um alias para a struct Pessoa
   using PessoaAlias = Pessoa;

   // Declarando uma variável do tipo PessoaAlias
   PessoaAlias p1;
   
   // Inicializando a struct
   p1.nome = "Ana";
   p1.idade = 30;
   p1.altura = 1.60;

   // Exibindo os dados da pessoa
   cout << "Nome: " << p1.nome << endl;
   cout << "Idade: " << p1.idade << endl;
   cout << "Altura: " << p1.altura << " metros" << endl;
}

// 4. Como enviar uma struct para uma função em C++
// Em C++, assim como em C, podemos passar uma struct para uma função de duas formas:
// - Por Valor: Faz uma cópia da struct. Qualquer modificação na função não afeta o original.
// - Por Referência: Passa o endereço da struct, permitindo que a função modifique diretamente seu conteúdo.
void imprimirPessoa(Pessoa p) {
   cout << "Nome: " << p.nome << " - idade " << p.idade << endl;
}

// Função que recebe a struct por referência (modifica os dados diretamente)
void atualizarIdade(Pessoa& p) {
   p.idade += 1;  // Incrementa a idade
}

void exemploPassagemStruct() {
   // Criando a variável do tipo Pessoa
   Pessoa p1 = {"Marina", 25, 1.54};

   // Enviando a struct por valor
   imprimirPessoa(p1); // Passa uma cópia de p1 para a função

   // Enviando a struct por referência
   atualizarIdade(p1); // Passa p1 por referência, então a idade será modificada

   // Exibindo os dados após a modificação
   cout << "Após atualização" << endl;
   imprimirPessoa(p1); // Mostra a idade atualizada
}

int main() {
   // Chamando todas as funções para demonstrar os exemplos:
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
}