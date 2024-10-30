#include <iostream>
using namespace std;

int main() {
    // Declaração de constantes
    const int NUM_LADOS = 4;             // Número de lados do retângulo (constante)
    const double CM_PARA_METROS = 0.01;  // Fator de conversão de centímetros para metros

    double comprimento, largura;

    // Solicitar e validar o comprimento
    cout << "Digite o comprimento do retângulo em centímetros: ";
    cin >> comprimento;
    if (comprimento <= 0) {
        cout << "Erro: O comprimento deve ser um valor positivo." << endl;
        return 1; // Encerra o programa se o valor for inválido
    }

    // Solicitar e validar a largura
    cout << "Digite a largura do retângulo em centímetros: ";
    cin >> largura;
    if (largura <= 0) {
        cout << "Erro: A largura deve ser um valor positivo." << endl;
        return 1; // Encerra o programa se o valor for inválido
    }

    // Cálculo do perímetro em centímetros
    double perimetro_cm = 2 * (comprimento + largura);

    // Cálculo do perímetro em metros
    double perimetro_metros = perimetro_cm * CM_PARA_METROS;

    // Exibir os resultados
    cout << "Perímetro do retângulo: " << perimetro_cm << " cm" << endl;
    cout << "Perímetro do retângulo: " << perimetro_metros << " metros" << endl;

    return 0;
}