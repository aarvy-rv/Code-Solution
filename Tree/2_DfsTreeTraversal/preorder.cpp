#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

void preOrderTraversal(Node* node){

    if(node == NULL){
        return;
    }

    cout << node->data;
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}
int main(){

}