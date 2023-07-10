#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    uint32_t data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} LinkedList;

void initializeList(LinkedList* list){
    list->head = NULL;
}

void insetAtBeginnning(LinkedList* list, uint32_t data){
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
}

void insertAtTheEnd(LinkedList* list, uint32_t data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        return;
    }

    Node* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void printList(const LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {

    LinkedList list;

    initializeList(&list);

    insertAtBeginning(&list, 3);
    insertAtBeginning(&list, 2);
    insertAtEnd(&list, 4);
    insertAtEnd(&list, 5);

    printf("Linked list: ");
    printList(&list);

    return 0;
}
