#include <iostream>   
#include <vector>     
#include <string>    
using namespace std;

// Definindo a estrutura Produto
struct Produto {
    string nome;            
    int quantidadeInicial;  
    int quantidadeVendida; 
    float valorVenda;      

    // Função membro que calcula a quantidade restante em estoque
    // Ao usar o const dentro do struct, vc esta dizendo "Eu prometo que essa função não vai alterar nenhum atributo da struct (ou class) no qual ela está sendo chamada." ou seja NÃO modifica o objeto da struct.
    int estoqueRestante() const {
        return quantidadeInicial - quantidadeVendida;
    }
};

int main() {
    int n;  // Variável para armazenar a quantidade de produtos que o usuário quer cadastrar

    // Pergunta ao usuário quantos produtos deseja cadastrar
    cout << "Quantos produtos deseja cadastrar? ";
    cin >> n;
    cin.ignore(); // Limpa o caractere de nova linha deixado no buffer após o cin, em resumo se tu der espaco ele vai limpar esse espaco e vai apenas pegar o caractere digitado antes de uma nova linha

    // Cria um vetor de 'n' produtos
    //O tipo Produto foi definido com a struct, então produtos é basicamente um "array flexível" de produtos. Exemplo: se o usuário digitar 3, o vector vai conter 3 structs Produto vazias (com valores padrão).
    vector<Produto> produtos(n);

    // Loop para preencher os dados de cada produto
    //para cada produto p dentro da prateleira produtos faça alguma coisa com p(esse p e um nome temporario que dei a ele) o auto faz o compilador descobrir o tipo automaticamente, no caso aqui e Produto, mas se tivesse outros structs teria que usar outra letra se criasse 2 vetores por exemplo, p : produtos se referindo a Produto, e c : clientes se referindo a Cliente
    for (auto& p : produtos) {
        // Lê o nome do produto (usando getline para permitir espaços)
        cout << "\nNome: ";
        getline(cin, p.nome);

        // Lê a quantidade inicial em estoque
        cout << "Quantidade inicial: ";
        cin >> p.quantidadeInicial;

        // Lê a quantidade que foi vendida
        cout << "Quantidade vendida: ";
        cin >> p.quantidadeVendida;

        // Lê o valor de venda
        cout << "Valor de venda: ";
        cin >> p.valorVenda;

        cin.ignore(); // Limpa o buffer antes de usar getline novamente no próximo loop
    }

    // Exibe o nome e a quantidade restante de cada produto
    //Aqui usamos const auto& porque não vamos modificar os dados, só queremos acessar.
    cout << "\n--- Estoque Restante ---\n";
    for (const auto& p : produtos) {
        cout << p.nome << ": " << p.estoqueRestante() << " unidades\n";
    }
    return 0;
}