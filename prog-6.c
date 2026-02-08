#include <stdio.h>
#define MAX 100

int minHeap[MAX], maxHeap[MAX];
int minSize = 0, maxSize = 0;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;
    
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

void printHeap(int heap[], int size, char* type) {
    printf("%s Heap: ", type);
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int arr[] = {4, 10, 3, 5, 1, 8, 2};
    int n = 7;
    
    printf("Original Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n");
    
    for (int i = 0; i < n; i++) minHeap[i] = arr[i];
    minSize = n;
    buildMinHeap(minHeap, minSize);
    printHeap(minHeap, minSize, "Min");
   
    for (int i = 0; i < n; i++) maxHeap[i] = arr[i];
    maxSize = n;
    buildMaxHeap(maxHeap, maxSize);
    printHeap(maxHeap, maxSize, "Max");
    
    printf("\nMin Heap Root (minimum): %d\n", minHeap[0]);
    printf("Max Heap Root (maximum): %d\n", maxHeap[0]);
    
    return 0;
}
