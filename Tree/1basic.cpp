#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
    }
};


int main(){

    Node* root = new Node(2);
    Node* left = new Node(3);
    Node* right = new Node(4);

    root->left = left;
    root->right = right; 

    cout << "hello";

}