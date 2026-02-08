(a) Data Structures
int minHeap[MAX], maxHeap[MAX];  // Array-based complete binary trees
int minSize, maxSize;            // Current heap sizes
Min Heap: Parent ≤ both children (root holds minimum)

Max Heap: Parent ≥ both children (root holds maximum)

Array indexing: Parent(i), Left(2i+1), Right(2i+2)

(b) Functions Implemented
minHeapify(arr, n, i): Restore min-heap property from index i downward

buildMinHeap(arr, n): Convert array to min heap (bottom-up O(n))

maxHeapify(arr, n, i): Restore max-heap property from index i downward

buildMaxHeap(arr, n): Convert array to max heap (bottom-up O(n))

swap(a, b): Exchange two array elements

(c) main() Organization
1. Define unsorted input array [4,10,3,5,1,8,2]
2. Copy → buildMinHeap() → print min heap
3. Copy → buildMaxHeap() → print max heap
4. Display root values (min/max verification)

(d) Sample Output
Original Array: 4 10 3 5 1 8 2 

Min Heap: 1 4 2 5 10 8 3 
Max Heap: 10 5 8 4 1 3 2 

Min Heap Root (minimum): 1
Max Heap Root (maximum): 10