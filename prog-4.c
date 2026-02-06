#include <stdio.h>
#include <stdlib.h>

struct Node
 {
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    
    new_node->next = prev_node->next;
    new_node->prev = prev_node;
    
    if (prev_node->next != NULL)
        prev_node->next->prev = new_node;
    
    prev_node->next = new_node;
}

void deleteNode(struct Node** head_ref, struct Node* del_node) {
    if (*head_ref == NULL || del_node == NULL)
        return;
    
    if (*head_ref == del_node)
        *head_ref = del_node->next;
    
    if (del_node->next != NULL)
        del_node->next->prev = del_node->prev;
    
    if (del_node->prev != NULL)
        del_node->prev->next = del_node->next;
    
    free(del_node);
}

void displayForward(struct Node* node) {
    printf("Forward: ");
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


void displayBackward(struct Node* node) {
    printf("Backward: ");
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->prev;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
   
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    
    head->data = 1;
    head->prev = NULL;
    head->next = second;
    
    second->data = 2;
    second->prev = head;
    second->next = third;
    
    third->data = 3;
    third->prev = second;
    third->next = NULL;
    
    printf("Original list:\n");
    displayForward(head);
    displayBackward(third);
    
  
    printf("\nInsert 4 after node 2:\n");
    insertAfter(second, 4);
    displayForward(head);
    

    struct Node* fourth = second->next;
    insertAfter(fourth, 5);
    printf("Insert 5 after node 4:\n");
    displayForward(head);
   
    printf("\nDelete node 2:\n");
    deleteNode(&head, second);
    displayForward(head);
   
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}
