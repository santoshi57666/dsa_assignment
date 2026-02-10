(a) Data Structures
text
int arr[MAX];         // Array to store N random integers [1,1000]
int comparisons, swaps; // Performance counters
int n;                // User-specified array size
int temp[MAX];        // MergeSort temporary array

(b) Functions Implemented
bubbleSort(): Adjacent swaps, O(n²) comparisons/swaps

selectionSort(): Min selection per pass, O(n²) comparisons

insertionSort(): Insert elements into sorted prefix

mergeSort(int left, int right): Divide-conquer + merge, O(n log n)

merge(): Merges two sorted subarrays

(c) main() Organization
1. User input N → generate N random ints [1,1000]
2. Print original array
3. User chooses algorithm (1-4)
4. Reset counters → execute chosen sort
5. Print sorted array + performance metrics

(d) Sample Output
Enter number of elements (1-1000): 8
Before sorting: 343 71 186 72 270 213 916 93 

Choose sorting algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
Enter choice (1-4): 1
Bubble Sort completed
After sorting: 71 72 93 186 213 270 343 916
Comparisons: 28, Swaps: 12