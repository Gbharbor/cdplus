#include <iostream> 
#include <fstream>  
#include <string>   
using namespace std;

void openFile(){
   string filename, line;  // Declara duas variáveis: uma para o nome do arquivo e outra para armazenar as linhas lidas

   cout << "nome do arquivo p/ abrir";  // Solicita ao usuário o nome do arquivo a ser aberto
   cin >> filename;  // Lê o nome do arquivo inserido pelo usuário

   ifstream file(filename);  // Abre o arquivo para leitura
   if(file.is_open()){  // Verifica se o arquivo foi aberto corretamente
      cout << "\nconteudo\n";
      // Lê o arquivo linha por linha e imprime cada linha na tela
      while(getline(file, line)) cout << line << endl;  // Enquanto houver uma linha no arquivo, ela é lida e impressa
      // O while(getline) cria um loop para ler o arquivo até o final:
      // - Lê uma linha inteira do arquivo "file"
      // - Armazena essa linha na variável "line"
      // - Depois imprime a linha
      file.close();  // Fecha o arquivo após a leitura
   } else {
      cout << "erro ao abrir o arquivo\n";
   }
}
// Função para criar um novo arquivo e salvar conteúdo nele
void createFile() {
   string filename, content;  // Declara duas variáveis: uma para o nome do arquivo e outra para o conteúdo
   
   cout << "nome do arquivo txt: ";
   cin >> filename;  // Lê o nome do arquivo a ser criado
   cin.ignore();  // Limpa o buffer de entrada para evitar problemas ao usar getline depois do cin
   cout << "texto p/ salvar: ";
   getline(cin, content);  // Lê o texto completo (incluindo espaços) que o usuário digitar
   
   ofstream file(filename);  // Cria (ou sobrescreve) um arquivo com o nome fornecido
   if (file.is_open()) {
      file << content;  // Grava o conteúdo no arquivo
      file.close();  // Fecha o arquivo após gravar o conteúdo
      cout << "arquivo salvo c/ sucesso" << endl;
   } else {
      cout << "erro ao criar arquivo." << endl; 
   }
}
int main() {
   int option;
   do {
      cout << "menu:\n1-Abrir\n2-Novo\n3-Fechar\n Selecione: ";
      cin >> option;  // Lê a opção escolhida pelo usuário
      switch (option) {
         case 1: openFile(); break;  
         case 2: createFile(); break;
         case 3: cout << "Fechar menu\n"; break;
         default: cout << "apenas 1, 2 ou 3\n";
      }
   } while (option != 3);  // Repete até o usuário escolher a opção 3
   return 0;
}