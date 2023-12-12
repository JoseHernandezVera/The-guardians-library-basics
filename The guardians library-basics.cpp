#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

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

int main() {
    srand(time(0));
    int tamano = rand() % 11001 + 100000;

    cout << "El tamano es de " << tamano << endl;

    // Crear el arreglo de números aleatorios en el rango de 100000 a 110000 con posibilidad de repetición
    int *arr = new int[tamano];
    for (int i = 0; i < tamano; i++) {
        arr[i] = rand() % 100001;
    }

    // Medicion de tiempos
    double tiempo_selection = 0.0;
    double tiempo_bubble = 0.0;
    double tiempo_insertion = 0.0;

    auto inicio_selection = chrono::high_resolution_clock::now();
    selectionSort(arr, tamano);
    auto fin_selection = chrono::high_resolution_clock::now();
    tiempo_selection = chrono::duration<double, milli>(fin_selection - inicio_selection).count();

    auto inicio_bubble = chrono::high_resolution_clock::now();
    bubbleSort(arr, tamano);
    auto fin_bubble = chrono::high_resolution_clock::now();
    tiempo_bubble = chrono::duration<double, milli>(fin_bubble - inicio_bubble).count();

    auto inicio_insertion = chrono::high_resolution_clock::now();
    insertionSort(arr, tamano);
    auto fin_insertion = chrono::high_resolution_clock::now();
    tiempo_insertion = chrono::duration<double, milli>(fin_insertion - inicio_insertion).count();

    cout << "El algoritmo de selection sort se demoro " << tiempo_selection << " milisegundos en ejecutarse." << endl;
    cout << "El algoritmo de bubble sort se demoro " << tiempo_bubble << " milisegundos en ejecutarse." << endl;
    cout << "El algoritmo de insertion sort se demoro " << tiempo_insertion << " milisegundos en ejecutarse." << endl;

    // Liberar la memoria del arreglo
    delete[] arr;

    return 0;
}
