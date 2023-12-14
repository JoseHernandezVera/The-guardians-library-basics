#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <functional>

using namespace std;
using namespace chrono;

// Funciones para generar vectores
vector<int> generateWithoutDuplicates(int minSize, int maxSize) {
    random_device rd;
    mt19937 gen(rd());

    int size = uniform_int_distribution<int>(minSize, maxSize)(gen);

    vector<int> arr(size);
    iota(arr.begin(), arr.end(), 0); // Llenar con valores consecutivos
    shuffle(arr.begin(), arr.end(), gen);

    return arr;
}

vector<int> generateWithDuplicates(int minSize, int maxSize) {
    random_device rd;
    mt19937 gen(rd());

    int size = uniform_int_distribution<int>(minSize, maxSize)(gen);

    vector<int> arr(size);
    generate(arr.begin(), arr.end(), [&]() { return uniform_int_distribution<int>(0, size)(gen); });

    return arr;
}

vector<int> generateSorted(int minSize, int maxSize) {
    auto arr = generateWithoutDuplicates(minSize, maxSize);
    sort(arr.begin(), arr.end());
    return arr;
}

vector<int> generateReverseSorted(int minSize, int maxSize) {
    auto arr = generateWithoutDuplicates(minSize, maxSize);
    sort(arr.rbegin(), arr.rend());
    return arr;
}

// Shell Sort
void shellSort(vector<int>& arr)
{
    int n = arr.size();

    for(int gap = n / 2; gap > 0; gap /= 2)
    {
        for(int i = gap; i < n; ++i)
        {
            int temp = arr[i];
            int j;

            for(j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}

// Selection Sort
void selectionSort(vector<int>& arr)
{
    int n = arr.size();

    for(int i = 0; i < n - 1; ++i)
    {
        int minIndex = i;

        for(int j = i + 1; j < n; ++j)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}

// Insertion Sort
void insertionSort(vector<int>& arr)
{
    int n = arr.size();

    for(int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}

// Merge Sort
void merge(vector<int>& arr, int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<int> leftArr(n1), rightArr(n2);

    for(int i = 0; i < n1; ++i)
    {
        leftArr[i] = arr[left + i];
    }
    for(int j = 0; j < n2; ++j)
    {
        rightArr[j] = arr[middle + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            ++i;
        }else
        {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    while(i < n1)
    {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }

    while(j < n2)
    {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<int>& arr, int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

// Heap Sort
void heapify(vector<int>& arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if(right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr)
{
    int n = arr.size();

    for(int i = n / 2 - 1; i >= 0; --i)
    {
        heapify(arr, n, i);
    }

    for(int i = n - 1; i > 0; --i)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Quick Sort
int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; ++j)
    {
        if(arr[j] < pivot)
        {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high)
{
    vector<pair<int, int>> stack;
    stack.push_back({low, high});

    while (!stack.empty())
    {
        low = stack.back().first;
        high = stack.back().second;
        stack.pop_back();

        int pi = partition(arr, low, high);

        if (pi - 1 > low)
        {
            stack.push_back({low, pi - 1});
        }

        if (pi + 1 < high)
        {
            stack.push_back({pi + 1, high});
        }
    }
}

// Bubble Sort
void bubbleSort(vector<int>& arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Función para medir el tiempo de ejecución
template <typename Func>
double measureTime(Func algorithm, vector<int> arr) {
    auto start = high_resolution_clock::now();
    algorithm(arr);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();
    return duration / 1000.0;
}

// Funciones de envoltura para algoritmos con parámetros adicionales
void wrapMergeSort(vector<int>& arr) {
    mergeSort(arr, 0, arr.size() - 1);
}

void wrapQuickSort(vector<int>& arr) {
    quickSort(arr, 0, arr.size() - 1);
}

// Funciones para carreras
void runRace(const vector<int>& data, const string& raceName) {
    cout << "\n\n ------ Carrera " << raceName << " ------\n\n";
    vector<pair<string, function<void(vector<int>&)>>> algorithms = {
        {"Selection Sort", selectionSort},
        {"Insertion Sort", insertionSort},
        {"Shell Sort", shellSort},
        {"Bubble Sort", bubbleSort},
        {"Merge Sort", wrapMergeSort},  // Usar la función de envoltura
        {"Heap Sort", heapSort},
        {"Quick Sort", wrapQuickSort}   // Usar la función de envoltura
    };

    for (const auto& algorithm : algorithms) {
        vector<int> copyData = data;
        double time = measureTime(algorithm.second, copyData);
        cout << algorithm.first << " tomó " << time << " segundos con un arreglo de " << data.size() << " elementos" << endl;
    }
}

// Función principal del programa
int main() {
    int option;

    do {
    	cout << "Menu de The guardians library-basics\n"
        cout << "\n1. Carrera con arreglo sin duplicados\n";
        cout << "2. Carrera con arreglo con duplicados\n";
        cout << "3. Carrera con arreglo ordenado\n";
        cout << "4. Carrera con arreglo ordenado en reversa\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> option;

        switch (option) {
            case 1: {
                auto withoutDuplicates = generateWithoutDuplicates(100000, 110000);
                runRace(withoutDuplicates, "con arreglo sin duplicados");
            }
            break;
            
            case 2: {
                auto withDuplicates = generateWithDuplicates(100000, 110000);
                runRace(withDuplicates, "con arreglo con duplicados");
            }
            break;
            
            case 3: {
                auto sorted = generateSorted(100000, 110000);
                runRace(sorted, "con arreglo ordenado");
            }
            break;
            
            case 4: {
                auto reverseSorted = generateReverseSorted(100000, 110000);
                runRace(reverseSorted, "con arreglo ordenado en reversa");
            }
            break;

            case 5: {
                cout << "\nCerrando el programa...";
            }
            break;

            default: {
                cout << "Opción inválida, por favor intente de nuevo...\n";
            }
            break;
        }
    } while (option != 5);

    return 0;
}