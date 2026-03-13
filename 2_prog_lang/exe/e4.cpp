#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <algorithm>

using namespace std;

// Função para escolher uma palavra aleatória da lista
string escolherPalavraAleatoria(const vector<string>& palavras) {
    srand(time(0)); // Inicializa a semente do gerador aleatório
    int indice = rand() % palavras.size(); // Seleciona um índice aleatório
    return palavras[indice];
}

// Função para atualizar o progresso da palavra
void atualizarProgresso(string& progresso, const string& palavra, char palpite) {
    for (size_t i = 0; i < palavra.size(); ++i) {
        if (palavra[i] == palpite) {
            progresso[i] = palpite;
        }
    }
}

// Função para verificar se o palpite já foi tentado
bool letraJaTentada(char palpite, const vector<char>& tentativas) {
    return find(tentativas.begin(), tentativas.end(), palpite) != tentativas.end();
}

int main() {
    // Lista de palavras pré-definidas
    vector<string> palavras = {"programacao", "computador", "elefante", "aventura", "lua", "janela"};

    // Seleciona uma palavra secreta aleatoriamente
    string palavraSecreta = escolherPalavraAleatoria(palavras);
    string progresso(palavraSecreta.size(), '_'); // Inicializa a palavra oculta com underscores
    int tentativasRestantes = 6; // Define o número máximo de tentativas
    vector<char> tentativas; // Vetor para armazenar letras já tentadas

    // Mensagem de boas-vindas e regras
    cout << "Bem-vindo ao jogo da Forca!\n";
    cout << "Regras: Tente adivinhar a palavra secreta letra por letra.\n";
    cout << "Voce tem " << tentativasRestantes << " tentativas para adivinhar a palavra.\n";

    // Laço principal do jogo
    while (tentativasRestantes > 0 && progresso != palavraSecreta) {
        cout << "\nPalavra: " << progresso << "\n";
        cout << "Tentativas restantes: " << tentativasRestantes << "\n";
        cout << "Letras ja tentadas: ";
        
        for (char t : tentativas) {
            cout << t << " ";
        }
        cout << "\n";

        // Solicita uma letra ao usuário
        char palpite;
        cout << "Digite uma letra: ";
        cin >> palpite;
        palpite = tolower(palpite); // Transforma o palpite para minúsculo

        // Verifica se a letra é válida e se já foi tentada
        if (!isalpha(palpite)) {
            cout << "Entrada invalida! Por favor, digite uma letra.\n";
            continue;
        }
        if (letraJaTentada(palpite, tentativas)) {
            cout << "Voce ja tentou essa letra. Tente outra.\n";
            continue;
        }

        // Adiciona o palpite ao vetor de tentativas
        tentativas.push_back(palpite);

        // Verifica se a letra está na palavra secreta
        if (palavraSecreta.find(palpite) != string::npos) {
            cout << "Boa! A letra '" << palpite << "' esta na palavra.\n";
            atualizarProgresso(progresso, palavraSecreta, palpite);
        } else {
            cout << "A letra '" << palpite << "' nao esta na palavra.\n";
            tentativasRestantes--; // Decrementa as tentativas restantes
        }
    }

    // Resultado final do jogo
    if (progresso == palavraSecreta) {
        cout << "\nParabens! Voce adivinhou a palavra secreta: " << palavraSecreta << "\n";
    } else {
        cout << "\nQue pena! Voce perdeu. A palavra secreta era: " << palavraSecreta << "\n";
    }

    return 0;
}