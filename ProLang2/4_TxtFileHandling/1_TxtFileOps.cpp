#include <iostream>
#include <fstream>  // Biblioteca fstream
#include <string>

using namespace std;

int main() {
    // ---------- Escrita com ofstream ----------
    ofstream arquivoEscrita;
    // ios::out + ios::trunc (padrão ao usar apenas ofstream)
    arquivoEscrita.open("exemplo_escrita.txt", ios_base::out | ios_base::trunc);
    arquivoEscrita << "Linha 1: Texto gravado com ofstream.\n";
    arquivoEscrita << "Linha 2: Outro texto qualquer.\n";
    arquivoEscrita.close();

    // ---------- Leitura com ifstream ----------
    ifstream arquivoLeitura;
    // ios::in é o padrão para ifstream, mas estamos explicitando aqui
    arquivoLeitura.open("exemplo_escrita.txt", ios_base::in);

    if (arquivoLeitura.is_open()) {
        cout << "\n--- Leitura caractere por caractere ---\n";
        char letra;
        while (arquivoLeitura.get(letra)) {
            cout << letra;
        }

        arquivoLeitura.clear();              // Limpa flags de EOF
        arquivoLeitura.seekg(0);             // Volta ao início do arquivo

        cout << "\n\n--- Leitura com vetor de caracteres (getline) ---\n";
        char vetor[80];
        while (arquivoLeitura.getline(vetor, 80)) {
            cout << vetor << endl;
        }

        arquivoLeitura.clear();
        arquivoLeitura.seekg(0);

        cout << "\n--- Leitura linha por linha (getline com string) ---\n";
        string texto;
        while (getline(arquivoLeitura, texto)) {
            cout << texto << endl;
        }

        arquivoLeitura.close();
    } else {
        cout << "Erro ao abrir o arquivo para leitura." << endl;
    }

    // ---------- Escrita no final com ios::app ----------
    ofstream arquivoAppend;
    // Abre o arquivo e adiciona conteúdo ao final
    arquivoAppend.open("exemplo_escrita.txt", ios_base::app);
    arquivoAppend << "Linha 3: Essa linha foi adicionada com ios::app\n";
    arquivoAppend.close();

    // ---------- Leitura e Escrita com fstream ----------
    fstream arquivoLeituraEscrita;
    // Abre o arquivo para leitura, escrita, move o cursor para o final, e mantém o conteúdo existente
    arquivoLeituraEscrita.open("exemplo_fstream.txt", ios_base::in | ios_base::out | ios_base::app);

    if (arquivoLeituraEscrita.is_open()) {
        arquivoLeituraEscrita << "Nova linha adicionada com fstream.\n";

        // Volta ao início do arquivo para leitura
        arquivoLeituraEscrita.seekg(0);

        cout << "\n--- Leitura com fstream (modo app) ---\n";
        string linha;
        while (getline(arquivoLeituraEscrita, linha)) {
            cout << linha << endl;
        }

        arquivoLeituraEscrita.close();
    } else {
        cout << "Erro ao abrir arquivo com fstream." << endl;
    }

    // ---------- Abertura em modo binário ----------
    ofstream arquivoBinario;
    arquivoBinario.open("exemplo_binario.dat", ios_base::out | ios_base::binary);
    if (arquivoBinario.is_open()) {
        string dados = "Arquivo salvo em modo binário\n";
        arquivoBinario.write(dados.c_str(), dados.size());
        arquivoBinario.close();
        cout << "\n--- Arquivo salvo em modo binário ---\n";
    }

    // ---------- Abertura com ios::ate ----------
    fstream arquivoComAte;
    arquivoComAte.open("exemplo_ate.txt", ios_base::in | ios_base::out | ios_base::ate);
    if (arquivoComAte.is_open()) {
        arquivoComAte << "Escrevendo no final com ios::ate\n";
        arquivoComAte.seekg(0); // Volta ao início para leitura
        string l;
        cout << "\n--- Leitura após ios::ate ---\n";
        while (getline(arquivoComAte, l)) {
            cout << l << endl;
        }
        arquivoComAte.close();
    }

    return 0;
}