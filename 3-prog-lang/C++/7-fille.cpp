#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// ------------------------------------------------------------
// Função 1: leitura caractere por caractere
// ------------------------------------------------------------
void lerCaracterePorCaractere(ifstream& ficheiro) {
    cout << "\n--- Leitura caractere por caractere ---\n";

    char ch;

    while (ficheiro.get(ch)) {
        cout << ch;
    }

    // Limpa os flags de erro (como EOF) e volta ao início do ficheiro
    ficheiro.clear();
    ficheiro.seekg(0);
}

// ------------------------------------------------------------
// Função 2: leitura com array de caracteres
// ------------------------------------------------------------
void lerComArrayDeCaracteres(ifstream& ficheiro) {
    cout << "\n\n--- Leitura com array de caracteres (getline) ---\n";

    char buffer[80];

    while (ficheiro.getline(buffer, 80)) {
        cout << buffer << endl;
    }

    // Limpa os flags de erro e volta ao início do ficheiro
    ficheiro.clear();
    ficheiro.seekg(0);
}

// ------------------------------------------------------------
// Função 3: leitura linha por linha com string
// ------------------------------------------------------------
void lerLinhaPorLinha(ifstream& ficheiro) {
    cout << "\n--- Leitura linha por linha (getline com string) ---\n";

    string linha;

    while (getline(ficheiro, linha)) {
        cout << linha << endl;
    }
}

int main() {

    // --------------------------------------------------------
    // 1. Escrita com ofstream
    // --------------------------------------------------------
    /*
       ofstream = output file stream
       Usado para escrever em ficheiros.
       
       ios::out   -> modo de escrita
       ios::trunc -> apaga o conteúdo anterior do ficheiro
    */
    ofstream writeFile("example_write.txt", ios::out | ios::trunc);

    writeFile << "Linha 1: Texto escrito com ofstream.\n";
    writeFile << "Linha 2: Outro texto qualquer.\n";

    writeFile.close();


    // --------------------------------------------------------
    // 2. Leitura com ifstream
    // --------------------------------------------------------
    /*
       ifstream = input file stream
       Usado para ler ficheiros.
    */
    ifstream readFile("example_write.txt", ios::in);

    if (readFile.is_open()) {
        lerCaracterePorCaractere(readFile);   // leitura caractere a caractere
        lerComArrayDeCaracteres(readFile);    // leitura com array de char
        lerLinhaPorLinha(readFile);           // leitura com string

        readFile.close();
    } else {
        cout << "Erro ao abrir o ficheiro para leitura." << endl;
    }


    // --------------------------------------------------------
    // 3. Acrescentar conteúdo com ios::app
    // --------------------------------------------------------
    /*
       ios::app = append
       Adiciona conteúdo ao final do ficheiro sem apagar o que já existe.
    */
    ofstream appendFile("example_write.txt", ios::app);

    appendFile << "Linha 3: Esta linha foi adicionada com ios::app\n";

    appendFile.close();


    // --------------------------------------------------------
    // 4. fstream: leitura + escrita + append
    // --------------------------------------------------------
    /*
       fstream permite ler e escrever no mesmo ficheiro.
       
       ios::in  -> leitura
       ios::out -> escrita
       ios::app -> acrescenta no final
    */
    fstream rwFile("example_fstream.txt", ios::in | ios::out | ios::app);

    if (rwFile.is_open()) {
        rwFile << "Nova linha adicionada com fstream.\n";

        rwFile.seekg(0);

        cout << "\n--- Leitura com fstream (modo app) ---\n";

        string linha;
        while (getline(rwFile, linha)) {
            cout << linha << endl;
        }

        rwFile.close();
    } else {
        cout << "Erro ao abrir o ficheiro com fstream." << endl;
    }


    // --------------------------------------------------------
    // 5. Modo binário
    // --------------------------------------------------------
    /*
       ios::binary abre o ficheiro em modo binário.
       Neste exemplo, gravamos uma sequência de bytes no ficheiro.
    */
    ofstream binFile("example_binary.dat", ios::out | ios::binary);

    if (binFile.is_open()) {
        string binData = "Ficheiro gravado em modo binario\n";

        binFile.write(binData.c_str(), binData.size());

        binFile.close();

        cout << "\n--- Ficheiro gravado em modo binario ---\n";
    }


    // --------------------------------------------------------
    // 6. ios::ate
    // --------------------------------------------------------
    /*
       ios::ate abre o ficheiro e posiciona o cursor no final logo no início.
       Diferente de ios::app, ainda é possível mover o cursor depois.
    */
    fstream ateFile("example_ate.txt", ios::in | ios::out | ios::ate);

    if (ateFile.is_open()) {
        ateFile << "Escrita no final usando ios::ate\n";

        ateFile.seekg(0);

        cout << "\n--- Leitura após uso de ios::ate ---\n";

        string linha;
        while (getline(ateFile, linha)) {
            cout << linha << endl;
        }

        ateFile.close();
    } else {
        cout << "Erro ao abrir o ficheiro com ios::ate." << endl;
    }

    return 0;
}