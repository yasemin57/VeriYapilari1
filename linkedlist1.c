#include <stdio.h>
#include <stdlib.h> 
struct Node {
    int data;            
    struct Node *next;   
};

struct Node *head = NULL;


struct Node* create_node(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("HATA: Bellek ayrılamadı.\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void create_or_add(int val) {
    if (head == NULL) {
        head = create_node(val);
        printf("Liste oluşturuldu ve ilk eleman (%d) eklendi.\n", val);
    } else {
   
        insert_at_end(val);
    }
}


void traverse_and_print() {
    struct Node *current = head;
    
    if (current == NULL) {
        printf("Liste boş.\n");
        return;
    }
    
    printf("\nListe Elemanları (Traversal): ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next; 
    }
    printf("NULL\n");
}


void insert_at_beginning(int val) {
    struct Node* newNode = create_node(val);
    
    newNode->next = head; 
    printf("%d başa eklendi.\n", val);
}


void insert_at_end(int val) {
    struct Node* newNode = create_node(val);
    
    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode; 
    printf("%d sona eklendi.\n", val);
}

void insert_after_value(int val, int key) {
    struct Node* current = head;

    while (current != NULL && current->data != key) {
        current = current->next;
    }

    if (current == NULL) {
        printf("HATA: %d değeri listede bulunamadı. Ekleme yapılamadı.\n", key);
        return;
    }
    
    struct Node* newNode = create_node(val);
    newNode->next = current->next; 
    current->next = newNode;   
    printf("%d, %d değerinden sonra eklendi.\n", val, key);
}


void delete_node(int key) {
    struct Node *temp = head;
    struct Node *prev = NULL;

    if (temp != NULL && temp->data == key) {
        head = temp->next; 
        free(temp);        
        printf("%d (başlangıç) silindi.\n", key);
        return;
    }
   
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("HATA: %d değeri listede bulunamadı. Silme yapılamadı.\n", key);
        return;
    }

    prev->next = temp->next; 
    free(temp);              
    printf("%d silindi.\n", key);
}


int main() {
    printf("--- Linked List İşlemleri ---\n");

    create_or_add(10);
    create_or_add(20); 
    insert_at_end(40); 
    traverse_and_print(); 

    insert_at_beginning(5); 
    traverse_and_print();

    insert_after_value(30, 20); 
    traverse_and_print();

    delete_node(5);  
    delete_node(40); 
    delete_node(20); 
    delete_node(99); 
    traverse_and_print();
    
    delete_node(10);
    delete_node(30);
    traverse_and_print();

    return 0;
}
