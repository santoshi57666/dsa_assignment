#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

int arr[MAX];
int comparisons = 0, swaps = 0;
int n;

void bubbleSort() {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            comparisons++;
            if (arr[j] > arr[j+1]) {
                swaps++;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort() {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            swaps++;
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

void insertionSort() {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            swaps++;
            arr[j+1] = arr[j];
            j--;
        }
        if (j != i-1) swaps++;  // Key moved
        arr[j+1] = key;
    }
}

void merge(int left, int mid, int right) {
    int temp[MAX];
    int i = left, j = mid+1, k = left;
    
    while (i <= mid && j <= right) {
        comparisons++;
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
}

void mergeSort(int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid+1, right);
        merge(left, mid, right);
    }
}

void printArray(char* msg) {
    printf("%s", msg);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    srand(time(NULL));
    
    printf("Enter number of elements (1-%d): ", MAX);
    scanf("%d", &n);
    
    // Generate random numbers
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000 + 1;
    
    printArray("Before sorting: ");
    
    // Choose sorting algorithm
    int choice;
    printf("\nChoose sorting algorithm:\n");
    printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &choice);
    
    // Reset counters
    comparisons = 0; swaps = 0;
    
    // Execute chosen algorithm
    switch(choice) {
        case 1: bubbleSort(); printf("Bubble Sort completed\n"); break;
        case 2: selectionSort(); printf("Selection Sort completed\n"); break;
        case 3: insertionSort(); printf("Insertion Sort completed\n"); break;
        case 4: mergeSort(0, n-1); printf("Merge Sort completed\n"); break;
        default: printf("Invalid choice!\n"); return 1;
    }
    
    printArray("After sorting: ");
    printf("Comparisons: %d, Swaps: %d\n", comparisons, swaps);
    
    return 0;
}
