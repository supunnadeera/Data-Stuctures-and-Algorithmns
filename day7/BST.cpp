#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root == nullptr) {
    return;
  }
  traverseInOrder(root->left);
  cout << root->key << " ";
  traverseInOrder(root->right);
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    if(node == nullptr){
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        newNode->key = key;
        newNode->left =newNode->right= nullptr;
        return newNode;
    }
    if(key < node->key){
        node->left=insertNode(node->left,key);
    }else if(key > node->key){
        node->right=insertNode(node->right,key);
    }
    return node;

}

//find inorderPredecessor

struct node *inorderPredecessor(struct node *root){
    if(root == nullptr) return root;
    if(root->right == nullptr){
      return root;
    }
    return inorderPredecessor(root->left); 
    
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if(root == nullptr) return root;
    if(key < root->key){
        root->left = deleteNode(root->left,key);
    }else if(key > root->key){
        root->right =deleteNode(root->right,key);
    }
    else{
        if(root->left == nullptr && root->right == nullptr){
            return NULL;
        }else if(root->left == nullptr){
            struct node *temp = root->right;
            free(root);
            return temp;
        
        }else if(root->right == nullptr){
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp= inorderPredecessor(root->left);
        root->key = temp->key;
        root->left = deleteNode(root->left,temp->key);
        
    }
    return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}