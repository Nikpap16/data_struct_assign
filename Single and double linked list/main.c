#include <stdio.h>
#include <stdlib.h>

//Single list με διόρθωση στην remove_item

typedef struct Node {
    int item;
    struct Node* nextNode;
} Node;

typedef struct LinkedList {
    Node* head;
    int size;
} LinkedList;

LinkedList create_list() {
    LinkedList list;
    list.head = NULL;
    list.size = 0;
    return list;
}

void insert_left(LinkedList* list, int item) {
    Node* newNode = malloc(sizeof(Node));
    newNode->item = item;
    newNode->nextNode = list->head;
    list->head = newNode;
    list->size++;
}

void insert_right(LinkedList* list, int item) {
    Node* newNode = malloc(sizeof(Node));
    newNode->item = item;
    newNode->nextNode = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* last = list->head;
        while (last->nextNode != NULL)
            last = last->nextNode;
        last->nextNode = newNode;
    }

    list->size++;
}

Node* findNode(LinkedList* list, int item) {
    Node* cur = list->head;
    while (cur != NULL) {
        if (cur->item == item) return cur;
        cur = cur->nextNode;
    }
    return NULL;
}

Node* remove_left_s(LinkedList* list) {
    if (list->head == NULL) return NULL;

    Node* removed = list->head;
    list->head = removed->nextNode;
    list->size--;
    return removed;
}

Node* remove_right_s(LinkedList* list) {
    if (list->head == NULL) return NULL;

    Node* parent = NULL;
    Node* child = list->head;

    while (child->nextNode != NULL) {
        parent = child;
        child = child->nextNode;
    }

    if (parent != NULL)
        parent->nextNode = NULL;
    else
        list->head = NULL;

    list->size--;
    return child;
}

// Διορθωμένη remove_item ( λογικο ΚΑΙ αντι για Η')
Node* remove_item(LinkedList* list, int item) {
    if (list->head == NULL)
        return NULL;

   
    if (list->head->item == item) {
        Node* removed = list->head;
        list->head = removed->nextNode;
        list->size--;
        return removed;
    }

    Node* parent = list->head;
    Node* child = parent->nextNode;

    while (child != NULL && child->item != item) {
        parent = child;
        child = child->nextNode;
    }

    if (child == NULL)
        return NULL;

    parent->nextNode = child->nextNode;
    list->size--;
    return child;
}

// Διπλά συνδεδεμένη λίστα

typedef struct DNode {
    int item;
    struct DNode* next;
    struct DNode* prev;
} DNode;

typedef struct DoubleLinkedList {
    DNode* head;
    DNode* tail;
    int size;
} DoubleLinkedList;

DoubleLinkedList create_dlist() {
    DoubleLinkedList list;
    list.head = NULL;
    list.tail = NULL;
    list.size = 0;
    return list;
}

void insert_left_d(DoubleLinkedList* list, int item) {
    DNode* newNode = malloc(sizeof(DNode));
    newNode->item = item;
    newNode->prev = NULL;
    newNode->next = list->head;

    if (list->head != NULL)
        list->head->prev = newNode;
    else
        list->tail = newNode;

    list->head = newNode;
    list->size++;
}

void insert_right_d(DoubleLinkedList* list, int item) {
    DNode* newNode = malloc(sizeof(DNode));
    newNode->item = item;
    newNode->next = NULL;
    newNode->prev = list->tail;

    if (list->tail != NULL)
        list->tail->next = newNode;
    else
        list->head = newNode;

    list->tail = newNode;
    list->size++;
}

DNode* remove_left_d(DoubleLinkedList* list) {
    if (list->head == NULL) return NULL;

    DNode* removed = list->head;
    list->head = removed->next;

    if (list->head != NULL)
        list->head->prev = NULL;
    else
        list->tail = NULL;

    list->size--;
    return removed;
}

DNode* remove_right_d(DoubleLinkedList* list) {
    if (list->tail == NULL) return NULL;

    DNode* removed = list->tail;
    list->tail = removed->prev;

    if (list->tail != NULL)
        list->tail->next = NULL;
    else
        list->head = NULL;

    list->size--;
    return removed;
}

DNode* remove_item_d(DoubleLinkedList* list, int item) {
    DNode* node = list->head;

    while (node != NULL && node->item != item)
        node = node->next;

    if (node == NULL) return NULL;

    if (node->prev != NULL)
        node->prev->next = node->next;
    else
        list->head = node->next;

    if (node->next != NULL)
        node->next->prev = node->prev;
    else
        list->tail = node->prev;

    list->size--;
    return node;
}

/*===========================================
=                   MAIN                   =
===========================================*/

int main() {
    printf("Single Linked List\n");
    LinkedList list = create_list();
    insert_right(&list, 3);
    insert_left(&list, 2);
    insert_right(&list, 6);

    Node* r = remove_item(&list, 3);
    if (r != NULL) printf("Removed: %d\n", r->item);

    Node* f = findNode(&list, 3);
    if (f == NULL) printf("Node  not found\n");

    printf("\n Double Linked List \n");
    DoubleLinkedList dlist = create_dlist();
    insert_left_d(&dlist, 10);
    insert_right_d(&dlist, 20);
    insert_right_d(&dlist, 30);

    DNode* dr = remove_item_d(&dlist, 20);
    if (dr != NULL) printf("Removed: %d\n", dr->item);

    return 0;
}
