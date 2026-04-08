#include <iostream>
using namespace std;

// Função que verifica se um número é primo
bool prime(int x) {
   // Se x for menor ou igual a 1, retorna 'false' pois números menores que 2 não são primos
   if (x <= 1) return false;

   // Loop que verifica se x tem algum divisor além de 1 e ele mesmo
   // O loop vai até a raiz quadrada de x (e * e <= x) para otimizar a verificação
   for (int e = 2; e * e <= x; ++e)
      // Se x for divisível por 'e', então x não é primo, retorna 'false'
      if (x % e == 0) return false;

   // Se não encontrou divisores, x é primo, retorna 'true'
   return true;
}

// Função que imprime "primo" ou "não primo" com base no valor do resultado
void print(bool result) {
   // Usa o operador ternário para verificar o resultado
   // Se 'result' for 'true', imprime "primo", caso contrário, imprime "não primo"
   cout << (result ? "primo" : "n primo") << endl;
}

int main() {
   int num;
   // Lê um número do usuário
   cin >> num;

   // Chama a função 'prime' passando 'num' como argumento, 
   // e passa o resultado para a função 'print' para exibir se é primo ou não
   print(prime(num));

   // Retorna 0 indicando que o programa foi executado com sucesso
   return 0;
}