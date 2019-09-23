#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct node {
    int key;
    struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

// preorder
void preorder(struct node *root) {
    if (root != NULL) {
        preorder(root->right);
        printf("%d \n", root->key);
        preorder(root->left);
    }
}

// A utility function to insert a new node with given key in BST
struct node* insert(struct node* node, int key) {
    // If the tree is empty, return a new node 
    if (node == NULL) return newNode(key);
    // Otherwise, recur down the tree 
    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);
    // return the (unchanged) node pointer
    return node;
}


struct node * minValueNode(struct node* node) { 
    struct node* current = node; 
    while (current && current->left != NULL) 
        current = current->left; 
    return current; 
} 


struct node* deleteNode(struct node* root, int key) { 
    if (root == NULL) return root; 
    if (key < root->key) root->left = deleteNode(root->left, key); 
    else if (key > root->key) root->right = deleteNode(root->right, key); 
    else { 
        if (root->left == NULL) { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } else if (root->right == NULL) { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
        struct node* temp = minValueNode(root->right); 
        root->key = temp->key; 
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
} 

// Driver Program to test above functions
int main() {
    /* Let us create following BST
             50 
           /    \
          30    70
          / \   / \
        20 40  60 80                */
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    // print inoder traversal of the BST
    inorder(root);
    cout << endl;
    preorder(root);
    
    printf("\nDelete 50\n"); 
    root = deleteNode(root, 50); 
    inorder(root); 
    
    return 0;
}
