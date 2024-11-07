#include <iostream>
using namespace std;

int main() {
    int n1, n2, n3;

    // Leitura dos três números
    cout << "Digite o primeiro número (n1): ";
    cin >> n1;
    cout << "Digite o segundo número (n2): ";
    cin >> n2;
    cout << "Digite o terceiro número (n3): ";
    cin >> n3;

    // Estrutura if-else para encontrar o maior número
    if (n1 >= n2 && n1 >= n3) {
        cout << "O maior número é: " << n1 << endl;
    } 
    else if (n2 >= n1 && n2 >= n3) {
        cout << "O maior número é: " << n2 << endl;
    } 
    else {
        cout << "O maior número é: " << n3 << endl;
    }

    return 0;
}
