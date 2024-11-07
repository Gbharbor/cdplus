#include <iostream>
using namespace std;
int main() {
    cout<<"uso do break dentro de um loop for:\n";
    for (int i=0; i<10; i++) {
        if (i==5) {
            break; //interrompe quando i for igual a 5
        }
        cout<<"i = "<<i<<endl;
    }
    cout<<"Loop interrompido."<<endl;
    cout<<endl;

    cout<<"Uso do break em um loop aninhado:\n";
    for (int i=0; i <3; i++) { //externo
        for(int j=0; j<3; j++ ) { //interno
        if(j==1) {
            break; //interrompe apenas o loop interno
        }
        cout<<"i= "<<i<<",j="<<j<<endl;
        }
    }
    cout<<endl;
    
    return 0;
}
/*
Uso do break dentro de um loop for:
i = 0
i = 1
i = 2
i = 3
i = 4
Loop interrompido.
*/
/*
Uso do break em um loop aninhado:
i = 0, j = 0
i = 1, j = 0
i = 2, j = 0
*/