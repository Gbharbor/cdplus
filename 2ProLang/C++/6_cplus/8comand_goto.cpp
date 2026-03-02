#include <iostream>
int main() {
    using namespace std;
    int x = 10;
    //ex basic
    cout<<"Uso do goto: \n";
    if(x == 10) {
        goto etiqueta; //salta para a etiqueta
    }
    cout<<"este codigo ser aignorado"<<endl;
    etiqueta: //etiqueta para onde o programa pode saltar
        cout<<"Salto realizado com goto ! "<<endl;


    cout<<"\n Uso do goto em um loop:\n";
    int contador = 0;
    loop_inicio:
        if(contador < 5) {
            cout<<"Contador: "<<contador<<endl;
            contador++;
            goto loop_inicio; //retorna ao inicio do loop
        }
    

cout << "\nExemplo de goto para tratar erro:\n";
    int num;
    
    // Solicita ao usuário para digitar um número
    cout << "Digite um número (ou valor inválido para ver o erro): ";
    cin >> num;

    // Verifica se a entrada falhou (ou seja, se o usuário digitou algo que não é um número)
    if (cin.fail()) {
        // Limpa o estado de erro do `cin`, permitindo que ele funcione normalmente
        cin.clear(); 
        
        // Ignora a entrada inválida até o final da linha, descartando o valor incorreto
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        
        // Redireciona o fluxo do programa para a seção de erro
        goto erro;
    }

    // Exibe o número digitado, pois a entrada foi válida
    cout << "Número digitado: " << num << endl;

    // Salta para a seção final do programa, ignorando o bloco de tratamento de erro
    goto fim;

erro: 
    // Etiqueta de tratamento de erro:
    // Executada se `goto erro;` for chamado devido a uma entrada inválida
    cout << "Erro: Entrada inválida. Digite um número válido." << endl;

fim: 
    // Etiqueta de finalização:
    // Executada no final do programa, independentemente de erro ou sucesso na entrada
    cout << "Programa finalizado." << endl;
    
    return 0;
}