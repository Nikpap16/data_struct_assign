#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;


Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}


Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;

   
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else {
       

        // Case 1: No child or only RIGHT child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }

        // Case 2: Only LEFT child
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}


int main() {
    Node* root = NULL;

    // Εισαγωγή τιμών
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal before deletion:\n");
    inorder(root);

    // Διαγραφή
    root = deleteNode(root, 50);

    printf("\nInorder traversal after deletion of 50:\n");
    inorder(root);

    return 0;
}
