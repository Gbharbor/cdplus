#include <iostream>
#include <vector>
using namespace std;

// Função utilitária para imprimir um vetor
void imprimirVetor(const vector<int>& vetor) {
    for (int num : vetor)
        cout << num << " ";
    cout << endl;
}

//  Bubble Sort 
void bubbleSort(vector<int>& vetor) {
    int n = vetor.size();
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (vetor[j] > vetor[j + 1])
                swap(vetor[j], vetor[j + 1]);
}

//  Insertion Sort 
void insertionSort(vector<int>& vetor) {
    int n = vetor.size();
    for (int i = 1; i < n; ++i) {
        int chave = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}

//  Merge Sort 
void merge(vector<int>& vetor, int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    vector<int> esq(n1), dir(n2);

    for (int i = 0; i < n1; ++i)
        esq[i] = vetor[inicio + i];
    for (int j = 0; j < n2; ++j)
        dir[j] = vetor[meio + 1 + j];

    int i = 0, j = 0, k = inicio;

    while (i < n1 && j < n2) {
        if (esq[i] <= dir[j])
            vetor[k++] = esq[i++];
        else
            vetor[k++] = dir[j++];
    }

    while (i < n1)
        vetor[k++] = esq[i++];

    while (j < n2)
        vetor[k++] = dir[j++];
}

void mergeSort(vector<int>& vetor, int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

int main() {
    vector<int> vetorOriginal = {45, 35, 24, 23, 15, 12};

    cout << "Vetor Original:\n";
    imprimirVetor(vetorOriginal);

    // Bubble Sort
    vector<int> bubble = vetorOriginal;
    bubbleSort(bubble);
    cout << "\nBubble Sort:\n";
    imprimirVetor(bubble);

    // Insertion Sort
    vector<int> insertion = vetorOriginal;
    insertionSort(insertion);
    cout << "\nInsertion Sort:\n";
    imprimirVetor(insertion);

    // Merge Sort
    vector<int> merge = vetorOriginal;
    mergeSort(merge, 0, merge.size() - 1);
    cout << "\nMerge Sort:\n";
    imprimirVetor(merge);

    return 0;
}