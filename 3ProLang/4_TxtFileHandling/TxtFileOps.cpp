#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Função para ler o arquivo caractere por caractere
void readCharByChar(ifstream& file) {
    cout << "\n--- Character-by-character reading ---\n";
    char ch;
    while (file.get(ch)) {  // Lê um caractere por vez
        cout << ch;  // Exibe o caractere
    }
    // Limpa os flags de erro (como EOF) e volta para o início do arquivo
    file.clear();
    file.seekg(0);
}

// Função para ler o arquivo usando um array de caracteres
void readWithCharArray(ifstream& file) {
    cout << "\n\n--- Reading with character array (getline) ---\n";
    char buffer[80];  // Array para armazenar os dados lidos
    while (file.getline(buffer, 80)) {  // Lê uma linha por vez até o limite do array
        cout << buffer << endl;  // Exibe a linha lida
    }
    // Limpa os flags e volta ao início do arquivo
    file.clear();
    file.seekg(0);
}

// Função para ler o arquivo linha por linha usando uma string
void readLineByLine(ifstream& file) {
    cout << "\n--- Line-by-line reading (getline with string) ---\n";
    string line;
    while (getline(file, line)) {  // Lê uma linha por vez
        cout << line << endl;  // Exibe a linha lida
    }
}

int main() {
    // ---------- Writing with ofstream ----------
    // Cria um arquivo e escreve nele
    ofstream writeFile("example_write.txt", ios::out | ios::trunc);
    // Escreve texto no arquivo
    writeFile << "Line 1: Text written with ofstream.\n";
    writeFile << "Line 2: Some other text.\n";
    // Fecha o arquivo após escrever
    writeFile.close();

    // ---------- Reading with ifstream ----------
    // Abre o arquivo para leitura
    ifstream readFile("example_write.txt", ios::in);
    // Verifica se o arquivo foi aberto corretamente
    if (readFile.is_open()) {
        // Lê e exibe o conteúdo do arquivo usando diferentes métodos
        readCharByChar(readFile);  // Lê caractere por caractere
        readWithCharArray(readFile);  // Lê com array de caracteres
        readLineByLine(readFile);  // Lê linha por linha com string
        // Fecha o arquivo após a leitura
        readFile.close();
    } else {
        // Caso o arquivo não tenha sido aberto, exibe mensagem de erro
        cout << "Error opening the file for reading." << endl;
    }

    // ---------- Appending with ios::app ----------
    // Abre o arquivo para adicionar conteúdo ao final (sem sobrescrever)
    ofstream appendFile("example_write.txt", ios::app);
    // Adiciona uma nova linha ao arquivo
    appendFile << "Line 3: This line was added using ios::app\n";
    // Fecha o arquivo após adicionar o conteúdo
    appendFile.close();

    // ---------- fstream (read + write + append ::app) ----------
    // Abre o arquivo para leitura, escrita e adição de conteúdo
    fstream rwFile("example_fstream.txt", ios::in | ios::out | ios::app);
    if (rwFile.is_open()) {
        // Escreve uma nova linha no arquivo
        rwFile << "New line added using fstream.\n";
        // Volta para o início do arquivo para leitura
        rwFile.seekg(0);
        cout << "\n--- Reading with fstream (app mode) ---\n";
        string line;
        // Lê e exibe cada linha do arquivo
        while (getline(rwFile, line)) {
            cout << line << endl;
        }
        // Fecha o arquivo após a leitura e escrita
        rwFile.close();
    } else {
        // Caso o arquivo não tenha sido aberto, exibe mensagem de erro
        cout << "Error opening file with fstream." << endl;
    }

    // ---------- Binary mode ----------
    // Abre um arquivo no modo binário para escrever
    ofstream binFile("example_binary.dat", ios::out | ios::binary);
    if (binFile.is_open()) {
        // Texto que será gravado no formato binário
        string binData = "File saved in binary mode\n";
        // Grava o texto no arquivo binário
        binFile.write(binData.c_str(), binData.size());
        // Fecha o arquivo após a gravação
        binFile.close();
        cout << "\n--- File saved in binary mode ---\n";
    }

    // ---------- ios::ate ----------
    // Abre o arquivo no modo ios::ate, que posiciona o cursor no final
    fstream ateFile("example_ate.txt", ios::in | ios::out | ios::ate);
    if (ateFile.is_open()) {
        // Escreve no final do arquivo
        ateFile << "Writing at the end using ios::ate\n";
        // Volta para o início do arquivo para ler
        ateFile.seekg(0);
        cout << "\n--- Reading after ios::ate ---\n";
        string line;
        // Lê e exibe o conteúdo do arquivo
        while (getline(ateFile, line)) {
            cout << line << endl;
        }
        // Fecha o arquivo após a leitura
        ateFile.close();
    }

    return 0;
}