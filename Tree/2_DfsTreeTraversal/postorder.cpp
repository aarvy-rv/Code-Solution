#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

//Postorder: Left Right Root
void postorderTraversal(Node* node){
    if(node == NULL){
        return;
    }

    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout<<node->data;
}
