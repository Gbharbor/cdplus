#include <iostream>
using namespace std;

int main () {
    /*Constantes*/
    const int lados = 4;
    const double conversao = 0.01; //0.01 é a conversao de cm p/ m 
    double comprimento, largura;
    /*solicitacoes e validacoes*/
    cout << "Digite o comprimento (centrimentros)";
    cin >> comprimento;
    if (comprimento <= 0) {
        cout << "Erro : apenas valor positivo" <<endl;
        return 1; //encerra se der erro
    }
    cout <<"Digite a largura (centrimentros)";
    cin >> largura;
    if(largura <=0) {
        cout <<"erro: apenas valor positivo" <<endl;
        return 1; //encerra se der erro
    }
    /*Calculos*/
    double peri_cm = 2 * (comprimento + largura);
    double peri_m = peri_cm * conversao;
    /*Resultados*/
    cout << "Perimetro: " <<peri_cm << " centimetros" << endl;
    cout << "perimetro: " <<peri_m << " metros" << endl;
    return 0;
};