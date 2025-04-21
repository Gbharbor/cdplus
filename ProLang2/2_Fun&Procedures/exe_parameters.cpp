//exercicio da aula 2: Escreva um procedimento chamado troca que troca os valores dos parametros recebidos. Sua assinatura deve ser void troca(float*a, float*b).
#include <iostream>
using namespace std;
void troca (float* a, float* b) {
   float temp = *a;
   *a = *b; // quando n tem o * e como se mudasse a posicao da memoria, mas o que queremos o * "acessa o valor guardado naquele endereço".
   *b = temp;
}
int main() {
   float x = 5.0, y=10.0; //aqui eles sao passado por ref usando (&x, &y)
   cout<<"antes da troca  x = "<< x << ", y = "<< y <<endl;
   troca(&x, &y);// so usa o & nesse caso porque a função quer "float*"
   cout<<"depois da troca: x = "<< x <<", y = "<< y <<endl;
   return 0;
}