/*
Faça um programa na linguagem C/C++ que declare três vetores de inteiros, denominados V1, V2 e V3, ambos de tamanho n (valor informado pelo usuário) por meio da alocação dinâmica, e três ponteiros do tipo inteiro, denominados pt1, pt2 e pt3. Preencha os vetores V1 e V2 com valores inteiros informados pelo usuário e faça com que o ponteiro pt1 aponte para o vetor V1 e o ponteiro pt2 aponte para o vetor V2. A seguir, calcule a soma dos dois vetores V1 e V2, acessando os valores apenas por meio dos ponteiros pt1 e pt2, e armazene o resultado no vetor V3 por meio do ponteiro pt3. Por fim, mostre os valores do vetor V3 e desaloque os três vetores. 
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    int *V1, *V2, *V3;
    int *pt1, *pt2, *pt3;

    cout << "Digite o tamanho dos vetores: ";
    cin >> n;

    V1 = new int[n];
    V2 = new int[n];
    V3 = new int[n];

    pt1 = V1;
    pt2 = V2;
    pt3 = V3;

    cout << "Digite os valores do vetor V1:\n";
    for (int i = 0; i < n; i++) {
        cin >> *(pt1 + i);
    }

    cout << "Digite os valores do vetor V2:\n";
    for (int i = 0; i < n; i++) {
        cin >> *(pt2 + i);
    }

    for (int i = 0; i < n; i++) {
        *(pt3 + i) = *(pt1 + i) + *(pt2 + i);
    }

    cout << "Resultado da soma (V3):\n";
    for (int i = 0; i < n; i++) {
        cout << *(pt3 + i) << " ";
    }
    cout << endl;

    delete[] V1;
    delete[] V2;
    delete[] V3;

    return 0;
}
