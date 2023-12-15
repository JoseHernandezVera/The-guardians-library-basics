# The Guardians Library-Basic

### Descripción del Programa

El programa "The Guardians Library-Basic" simula carreras de algoritmos de ordenamiento utilizando conjuntos de datos diversos. Cada carrera representa una competencia entre algoritmos para determinar cuál puede ordenar un conjunto de datos específico en el menor tiempo posible.

## Generación de Vectores

Se proporcionan funciones para generar vectores con diferentes características:
#### Código
`vector<int> generateWithoutDuplicates(int minSize, int maxSize);`  
`vector<int> generateWithDuplicates(int minSize, int maxSize);`  
`vector<int> generateSorted(int minSize, int maxSize);`  
`vector<int> generateReverseSorted(int minSize, int maxSize);`  

#### Explicación de codigo
generateWithoutDuplicates:  
Genera un vector de tamaño aleatorio sin elementos duplicados y lo devuelve.

##### generateWithDuplicates:  
Genera un vector de tamaño aleatorio con elementos duplicados y lo devuelve.

##### generateSorted:  
Genera un vector de tamaño aleatorio y lo ordena de forma ascendente.

##### generateReverseSorted:  
Genera un vector de tamaño aleatorio y lo ordena de forma descendente.

## Algoritmos de Ordenamiento Implementados

Se implementan varios algoritmos de ordenamiento, cada uno en una función separada:
#### Código
`void shellSort(vector<int>& arr);`  
`void selectionSort(vector<int>& arr);`  
`void insertionSort(vector<int>& arr);`  
`void mergeSort(vector<int>& arr, int left, int right);`  
`void heapSort(vector<int>& arr);`  
`void quickSort(vector<int>& arr, int low, high);`  
`void bubbleSort(vector<int>& arr);`

#### Explicación de código
shellSort:  
Este algoritmo mejora el rendimiento del algoritmo de inserción al comparar y intercambiar elementos que están separados por una brecha específica en lugar de comparar elementos adyacentes directamente. A medida que el algoritmo progresa, la brecha se reduce, lo que eventualmente lleva a un ordenamiento completo.

##### selectionSort:    
Este algoritmo divide la lista en dos partes: una parte ordenada y otra no ordenada. En cada iteración, encuentra el elemento mínimo de la parte no ordenada y lo intercambia con el primer elemento no ordenado. Este proceso se repite hasta que toda la lista está ordenada.

##### insertionSort: 
Este algoritmo construye una parte ordenada de la lista al insertar elementos uno por uno en su posición correcta. En cada iteración, un elemento de la parte no ordenada se compara y mueve hacia la parte ordenada hasta que la lista completa está ordenada.

##### mergeSort:  
Este algoritmo utiliza la estrategia divide y vencerás. Divide la lista en mitades, ordena cada mitad recursivamente y luego combina las mitades ordenadas para obtener la lista final ordenada. Utiliza la función de fusión (merge) para combinar las sublistas ordenadas.

##### heapSort:  
Este algoritmo utiliza un montículo (heap) para organizar los elementos. Primero, construye un montículo máximo o mínimo (según el orden deseado). Luego, extrae repetidamente el elemento superior del montículo y lo coloca al final del arreglo, reduciendo la longitud del montículo y manteniendo la propiedad del montículo.

##### quickSort:  
Este algoritmo elige un elemento pivote y particiona la lista en dos partes: elementos menores que el pivote y elementos mayores que el pivote. Luego, aplica recursivamente el mismo proceso a las dos partes. La elección eficiente del pivote, como la mediana de tres, mejora el rendimiento en casos particulares.

##### bubbleSort:  
Este algoritmo compara y intercambia elementos adyacentes si están en el orden incorrecto. Este proceso se repite varias veces hasta que la lista está ordenada. Aunque es simple, su eficiencia es limitada y se utiliza principalmente para fines educativos o en situaciones con conjuntos de datos pequeños.

## Funciones de Medición del Tiempo

Se incluye una función para medir el tiempo de ejecución de los algoritmos:
#### Código
`template <typename Func>`  
`double measureTime(Func algorithm, vector<int> arr);`

#### Explicación de código
##### measureTime:  
Mide el tiempo que tarda un algoritmo de ordenamiento en ejecutarse sobre un vector dado y devuelve el tiempo en segundos.
### Carreras de Algoritmos

La función runRace ejecuta varios algoritmos en un conjunto de datos dado y determina el ganador basándose en el tiempo de ejecución.

### Función Principal y Menú

La función principal main presenta un menú interactivo que permite al usuario seleccionar diferentes tipos de carreras:

1. Carreras en la cola de espera
2. Carreras de trazabilidad de objetos
3. Carreras de eventos en cada escenario
4. Salir

El programa sigue ejecutándose hasta que el usuario elige salir.

### Link
https://github.com/JoseHernandezVera/The-guardians-library-basics
