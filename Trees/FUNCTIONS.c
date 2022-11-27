#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

struct node {
    int key;
    struct node *left, *right;
};
 

struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
 
    /* return the (unchanged) node pointer */
    return node;
}


//To print file sorted ID's of data_10
void inorder10(struct node* root)
{
    if (root != NULL) {
        inorder10(root->left);
        printf("%d \n", root->key);
        inorder10(root->right);
    }
}
//Sort for the rest of the files
void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        inorder(root->right);
    }
}



/*
void searchNode(struct node *temp, int value){  
    //Check whether tree is empty  
    if(root == NULL){  
        printf("Tree is empty\n");  
    }  
    else{  
        //If value is found in the given binary tree then, set the flag to true  
        if(temp->data == value){  
            flag = true;  
             return;  
        }  
        //Search in left subtree  
        if(flag == false && temp->left != NULL){  
        searchNode(temp->left, value);  
        }  
        //Search in right subtree  
        if(flag == false && temp->right != NULL){  
        searchNode(temp->right, value);  
        }  
    }  
} 
*/

struct node* minValueNode(struct node* node)
{
    struct node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
 
/* Given a binary search tree
   and a key, this function
   deletes the key and
   returns the new root */
struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL)
        return root;
 
    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted
    // is greater than the root's
    // key, then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key,
    // then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        struct node* temp = minValueNode(root->right);
 
        // Copy the inorder
        // successor's content to this node
        root->key = temp->key;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

bool find(struct node* node)
{
    if (node == NULL)
        return false;
 
    if (((node->key)%2)==0)
        return true;
 
    /* then recur on left sutree */
    bool res1 = find(node->left);
    // node found, no need to look further
    if(res1) 
		return true;
 
    /* node is not found in left,
    so recur on right subtree */
    bool res2 = find(node->right);
 
    return res2;
}


