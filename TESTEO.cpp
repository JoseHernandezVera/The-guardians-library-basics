#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Algoritmo de ordenamiento: Selection Sort
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

// Algoritmo de ordenamiento: Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Algoritmo de ordenamiento: Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Algoritmo de ordenamiento: Shell Sort
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}

// Algoritmo de ordenamiento: Merge Sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Algoritmo de ordenamiento: Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Algoritmo de ordenamiento: Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

struct AlgorithmInfo {
    string name;
    double duration;
};

// Sobrecarga para funciones de ordenamiento que toman dos argumentos
void runSortingAlgorithm(int arr[], int size, void (*sortingFunction)(int[], int), const string& algorithmName, vector<AlgorithmInfo>& algorithms) {
    int* arrCopy = new int[size];
    copy(arr, arr + size, arrCopy);

    auto start = high_resolution_clock::now();
    sortingFunction(arrCopy, size);
    auto stop = high_resolution_clock::now();
    double duration = duration_cast<milliseconds>(stop - start).count() / 1000.0;

    cout << algorithmName << " tiempo de ejecucion: " << duration << " segundos\n";
    algorithms.push_back({algorithmName, duration});

    delete[] arrCopy;
}

// Sobrecarga para funciones de ordenamiento que toman tres argumentos
void runSortingAlgorithm(int arr[], int size, void (*sortingFunction)(int[], int, int), const string& algorithmName, vector<AlgorithmInfo>& algorithms) {
    int* arrCopy = new int[size];
    copy(arr, arr + size, arrCopy);

    auto start = high_resolution_clock::now();
    sortingFunction(arrCopy, 0, size - 1);
    auto stop = high_resolution_clock::now();
    double duration = duration_cast<milliseconds>(stop - start).count() / 1000.0;

    cout << algorithmName << " tiempo de ejecucion: " << duration << " segundos\n";
    algorithms.push_back({algorithmName, duration});

    delete[] arrCopy;
}

// Función para encontrar el algoritmo más eficiente
AlgorithmInfo findMostEfficientAlgorithm(const vector<AlgorithmInfo>& algorithms) {
    auto minAlgorithm = min_element(algorithms.begin(), algorithms.end(),
        [](const AlgorithmInfo& a, const AlgorithmInfo& b) {
            return a.duration < b.duration;
        });

    return *minAlgorithm;
}

int main() {
    // Generar un número aleatorio entre 100,000 y 110,000 para determinar el tamaño del arreglo
    int size = rand() % 10001 + 100000;

    // Crear el arreglo con el tamaño aleatorio
    int* arr = new int[size];

    srand(time(0));
    // Llenar el arreglo con números aleatorios
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 110001;  // Puedes ajustar el rango según tus necesidades
    }

    // Almacenar información de cada algoritmo
    vector<AlgorithmInfo> algorithms;

    int choice;
    int choice2;
    
    cout << "Menu\n1. Cola de espera ";
    cout << "\nSelecciona una opcion: ";
    cin >> choice;

    switch (choice) {
        case 1:

        	cout << "\nEstas son las carreras:\n";
        	cout << "1. Aleatorios con numeros repetidos\n2. Aleatorios sin numeros repetidos\n3. Ordenado\n4. Inversamente ordenado";
        	cout << "Escoge una carrera: ";
        	cin >> choice2;
        	
        	switch (choice2) {
        		case 1:
        		
        		cout << "El tamano del arreglo es " << size << endl;

	            // Selection Sort
	            runSortingAlgorithm(arr, size, selectionSort, "Selection Sort", algorithms);
	
	            // Bubble Sort
	            runSortingAlgorithm(arr, size, bubbleSort, "Bubble Sort", algorithms);
	
	            // Insertion Sort
	            runSortingAlgorithm(arr, size, insertionSort, "Insertion Sort", algorithms);
	
	            // Shell Sort
	            runSortingAlgorithm(arr, size, shellSort, "Shell Sort", algorithms);
	
	            // Merge Sort
	            runSortingAlgorithm(arr, size, mergeSort, "Merge Sort", algorithms);
	
	            // Quick Sort
	            runSortingAlgorithm(arr, size, quickSort, "Quick Sort", algorithms);
	
	            // Heap Sort
	            runSortingAlgorithm(arr, size, heapSort, "Heap Sort", algorithms);
	
	            // Encontrar el algoritmo que se demoró menos
	            AlgorithmInfo minAlgorithm = findMostEfficientAlgorithm(algorithms);
	
	            // Imprimir resultados
	            cout << "\nEl algoritmo que se demoro menos fue: " << minAlgorithm.name;
	            cout << " se demoro " << minAlgorithm.duration << " segundos en ejecutarse.\n";
	
	            // Liberar la memoria de los arreglos dinámicos
	            delete[] arr;
	            
	            break;
        		
			}


            break;
    }

    return 0;
}
