#include <iostream>
#include <fstream>

using namespace std;

int main() {

    // ------------------------------------------------------------
    // 1. Escrita em arquivo
    // ------------------------------------------------------------

    /*
    ofstream = output file stream
    Usado para escrever dados em arquivos.
    */

    ofstream escreva;

    /*
    Abrimos o arquivo "texto.txt"

    ofstream::app significa:
    modo "append" → acrescenta conteúdo ao final do arquivo
    sem apagar o conteúdo existente.
    */

    escreva.open("texto.txt", ofstream::app);

    // Escrevendo no arquivo
    escreva << "teste arquivo" << endl;

    // Fechando o arquivo após a escrita
    escreva.close();


    // ------------------------------------------------------------
    // 2. Leitura de arquivo
    // ------------------------------------------------------------

    /*
    ifstream = input file stream
    Usado para ler dados de arquivos.
    */

    ifstream ler;

    char conjunto[50];  // buffer para armazenar cada linha lida

    ler.open("texto.txt");

    // Verifica se o arquivo foi aberto corretamente
    if (ler.is_open()) {

        /*
        getline lê uma linha do arquivo
        até encontrar quebra de linha ou atingir o limite do buffer.
        */

        while (ler.getline(conjunto, 50)) {

            cout << conjunto << endl;
        }

        // Fecha o arquivo após leitura
        ler.close();
    }

    return 0;
}