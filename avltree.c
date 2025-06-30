#include <stdio.h>
#include <stdlib.h>

// Define the structure
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};
typedef struct Node avl;

// Get the height of the tree
int height(avl *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// Get max of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Create a new node
avl* createNode(int data) {
    avl* newNode = (avl*)malloc(sizeof(avl));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->height = 1; // New node is initially at height 1
    return newNode;
}

// Right rotate
avl* rightRotate(avl* y) {
    avl* x = y->left;
    avl* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotate
avl* leftRotate(avl* x) {
    avl* y = x->right;
    avl* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Get balance factor
int getBalance(avl *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Insert into AVL tree
avl* insert(avl* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        return root; // No duplicates

    // Update height
    root->height = 1 + max(height(root->left), height(root->right));

    // Check balance
    int balance = getBalance(root);

    // Left Left
    if (balance > 1 && data < root->left->data)
        return rightRotate(root);

    // Right Right
    if (balance < -1 && data > root->right->data)
        return leftRotate(root);

    // Left Right
    if (balance > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left
    if (balance < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// In-order traversal
void inorder(avl* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void postorder(avl* root){
if(root != NULL){
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
}
void preorder(avl* root){
if(root != NULL){
   printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);

}
}

int main() {
  //  avl *root = NULL;
    //int values[] = {15, 9, 10, 25, 18, 85, 55, 79, 96};
    //int n = sizeof(values)/sizeof(values[0]);

    //for (int i = 0; i < n; i++) {
      //  root = insert(root, values[i]);
   // }

    //printf("Inorder Traversal of AVL Tree:\n");
    //inorder(root);
    //return 0;

    avl *root = NULL;

    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
 root = insert(root, 15);
  root = insert(root, 13);
   root = insert(root, 23);
    printf("Inorder Traversal of AVL Tree:\n");
    inorder(root);
     printf(" \n postorder Traversal of AVL Tree:\n");
    postorder(root);
    printf(" \n preorder Traversal of AVL Tree:\n");
    preorder(root);
    return 0;
}

