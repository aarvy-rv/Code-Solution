#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right; 
};

void inorderTraversal(Node* node){
    if(node == NULL){
        return;
    }

    inorderTraversal(node->left);
    cout << node->data<< " ";
    inorderTraversal(node->right);
}



int main(){

}