
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Estrutura para representar um produto
struct Product {
    string name;
    int initialQuantity;
    int quantitySold;
    float salePrice;
    // Função membro que calcula a quantidade restante em estoque
    int remainingStock() const { // o const não modifica o objeto da struct
        return initialQuantity - quantitySold;
    }
};
int main() {
    int totalProducts;
    cout << "Quantos produtos quer cadastrar? ";
    cin >> totalProducts;
    cin.ignore(); // limpa o caractere da nova linha deixado no buffer após o cin
    vector<Product> products(totalProducts); // vetor de produtos
    // Loop para cadastrar os produtos
    for (auto& product : products) {
        cout << "Nome: ";
        getline(cin, product.name); // lê espaços caso o nome tenha mais de uma palavra
        cout << "Quantidade inicial: ";
        cin >> product.initialQuantity;
        cout << "Quantidade vendida: ";
        cin >> product.quantitySold;
        cout << "Valor de venda: ";
        cin >> product.salePrice;
        cin.ignore(); // limpa o buffer para usar getline no próximo loop
    }
    // Exibe o nome e a quantidade restante de cada produto
    cout << "\nEstoque:\n";
    for (const auto& product : products) {
        cout << product.name << " = " << product.remainingStock() << " produtos em estoque\n";
    }
    return 0;
};