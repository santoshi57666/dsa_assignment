(a) Data Structures
Doubly Linked List Node:

struct Node {
    int data;           // Node value
    struct Node* next;  // Next node pointer
    struct Node* prev;  // Previous node pointer
};

Bidirectional pointers enable forward/backward traversal

head pointer manages list start

(b) Functions Implemented
insertAfter(Node* prev_node, int data): Inserts new node after prev_node (O(1))

deleteNode(Node** head_ref, Node* del_node): Removes specified node, updates links (O(1))

displayForward(Node* node): Prints list head→tail

displayBackward(Node* node): Prints list tail→head

(c) main() Organization

1. Create initial list: 1↔2↔3
2. Display original (forward/backward)
3. Insert 4 after node 2
4. Insert 5 after node 4  
5. Delete node 2
6. Memory cleanup

(d) Sample Output
Original list:
Forward: 1 2 3 
Backward: 3 2 1 

Insert 4 after node 2:
Forward: 1 2 4 3 
Insert 5 after node 4:
Forward: 1 2 4 5 3 

Delete node 2:
Forward: 1 4 5 3 