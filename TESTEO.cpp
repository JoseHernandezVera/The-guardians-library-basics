#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

double medirTiempo(void (*algoritmo)(int[], int), int arr[], int tamano) {
    auto inicio = chrono::high_resolution_clock::now();
    algoritmo(arr, tamano);
    auto fin = chrono::high_resolution_clock::now();
    return chrono::duration<double, milli>(fin - inicio).count() / 1000.0;
}

void mostrarTiempo(string nombre, double tiempo) {
    cout << "El algoritmo de " << nombre << " se demoro " << tiempo << " segundos en ejecutarse." << endl;
}

int main() {
    srand(time(0));
    int tamano = rand() % 11001 + 100000;

    cout << "El tamano es de " << tamano << endl;

    // Crear el arreglo de números aleatorios en el rango de 100000 a 110000 con posibilidad de repetición
    int *originalArr = new int[tamano];
    for (int i = 0; i < tamano; i++) {
        originalArr[i] = rand() % 100001;
    }

    // Crear copias del arreglo original para cada algoritmo
    int *arrSelection = new int[tamano];
    int *arrBubble = new int[tamano];
    int *arrInsertion = new int[tamano];

    // Copiar el contenido del arreglo original a las copias
    std::copy(originalArr, originalArr + tamano, arrSelection);
    std::copy(originalArr, originalArr + tamano, arrBubble);
    std::copy(originalArr, originalArr + tamano, arrInsertion);

    // Medicion de tiempos y mostrar resultados
    double tiempo_selection = medirTiempo(selectionSort, arrSelection, tamano);
    double tiempo_bubble = medirTiempo(bubbleSort, arrBubble, tamano);
    double tiempo_insertion = medirTiempo(insertionSort, arrInsertion, tamano);

    mostrarTiempo("selection sort", tiempo_selection);
    mostrarTiempo("bubble sort", tiempo_bubble);
    mostrarTiempo("insertion sort", tiempo_insertion);

    // Liberar la memoria de los arreglos
    delete[] originalArr;
    delete[] arrSelection;
    delete[] arrBubble;
    delete[] arrInsertion;

    return 0;
}
