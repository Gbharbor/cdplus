#include <iostream>
using namespace std;
int main() {
    //secao de operadores aritmeticos
    int x = 10, y = 3;
    int result;
    
    
    result = x + y; // * & /
    cout<<"adicao: "<<x<<"+"<<y<<"="<<result<<endl; //option 1
    cout<<"subtracao: "<<x<<"-"<<y<<"="<<x - y<<endl; //option 2
    
    //resto da divisao inteira: % 
    result = x % y;
    cout<<"resto da divisao inteira: "<<x<<"%"<<y<<"="<<result<<endl;

    //incremento x++ |decremento x--;
    cout<<"valor de x antes do incremento: "<< x <<endl;
    x++; //10
    cout<<"valor de x apos o incremento: " <<x<<endl; //11

    //Operadores logicos: 
    bool resultado;
  
    resultado = (x > 5) && (y < 30);  // and (&&) 
    cout<<"resultado de: "<<resultado<<endl;// 1 (true)

    resultado = (x < 5) || (y > 15); // or (||)
    cout<<"Resultado de: "<<resultado<<endl;//1 (true)

    resultado = !(x == 10); 
    cout<<"Resultado: "<<resultado<<endl;//0 (false)

    if(x < y) {
        cout<<"Expressao simples: x e menor q y"<<endl; //so uma condicao
    }
    if((x>5)&&(y<30)) {
        cout<<"x é maior q 5 e y e menor q 30"<<endl;//ambas precisam ser verdadeiras
    }

    //Estrutura condicional if, else-if, else
    int idade;
    cout<<"\nEnsira sua idade: ";
    cin>>idade;

    if(idade < 0) {
        cout<<"Idade invalida!"<<endl;
    } else if (idade < 18) {
        cout<<"Menor de idade !"<<endl;
    } else {
        cout<<"Maior de idade !"<<endl;
    }

    //other ex: 
    if (idade < 10) {
        cout<<"vc e uma crianca"<<endl;
    } else if(idade < 13) {
        cout<<"vc e uma pre adolecente"<<endl;
    } else if(idade < 20) {
        cout<<"vc e um adolecente"<<endl;
    } else if(idade < 65) {
        cout<<"vc e um adulto"<<endl;
    } else {
        cout<<"vc e um idoso"<<endl;
    }

    return 0;
}