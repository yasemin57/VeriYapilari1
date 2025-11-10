#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next; 
};

struct Node *head = NULL;

struct Node* create_node(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("HATA: Bellek ayrýlamadý.\n");
        exit(1);
    }
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void traverse_and_print() {
    struct Node *current = head;
    
    if (current == NULL) {
        printf("[Liste Boþ]\n");
        return;
    }
    
    printf("Liste: ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void insert_at_end(int val) {
    struct Node* newNode = create_node(val);

    if (head == NULL) {
        head = newNode;
        printf("%d listenin ilk elemaný olarak eklendi.\n", val);
        return;
    }

    struct Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode; 
    newNode->prev = current; 
    printf("%d sona eklendi.\n", val);
}

void insert_after_value(int val, int key) {
    struct Node* current = head;
    
    while (current != NULL && current->data != key) {
        current = current->next;
    }

    if (current == NULL) {
        printf("HATA: %d deðeri bulunamadý. Araya ekleme yapýlamadý.\n", key);
        return;
    }

    struct Node* newNode = create_node(val);
    struct Node* nextNode = current->next;

    newNode->next = nextNode; 
    newNode->prev = current;  
    current->next = newNode; 

    if (nextNode != NULL) {
        nextNode->prev = newNode; 
    }
    
    printf("%d, %d deðerinden sonra araya eklendi.\n", val, key);
}


void delete_recursive(struct Node* current) {
    if (current == NULL) {
        return; 
    }

    delete_recursive(current->next);

    printf("Siliniyor: %d\n", current->data);
    free(current);
}

void delete_all_elements() {
    printf("\n--- Recursive Silme Baþlatýldý ---\n");
    delete_recursive(head);
    head = NULL; 
    printf("--- Tüm liste silindi ve bellek serbest býrakýldý ---\n");
}


int main() {
    printf("--- Double Linked List Testi ---\n");
    
    insert_at_end(10);
    insert_at_end(20);
    insert_at_end(40);
    traverse_and_print(); 

    insert_after_value(30, 20); 
    traverse_and_print();
    
    insert_after_value(50, 40); 
    traverse_and_print();
    
    
    delete_all_elements();
    traverse_and_print();

    return 0;
}
