#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Tree{
    int data;
    Tree* left;
    Tree* right;

    Tree(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Tree* insertion(Tree* root,int val){
    if(root == NULL)
        return (new Tree(val));

    if(val < root->data){
        root->left = insertion(root->left,val);
    }
    if(val > root->data){
        root->right = insertion(root->right,val);
    }

    return root;
}

vector<vector<int>> bfs(Tree* root){

    vector<vector<int>> ans;

    queue<Tree*> q;

    if(root == NULL)
        return ans;

    q.push(root);

    while(!q.empty()){
        int n = q.size();
        vector<int> level;
        for(int i = 0;i<n;i++){

            Tree* node = q.front();
            q.pop();

            level.push_back(node->data);
            if(node->left != NULL)
                q.push(node->left);
            if(node->right != NULL)
                q.push(node->right);
        }
        ans.push_back(level);
    }

    return ans;

}

int main(){

    vector<int> nodes{14,10,20,4,12,17,11};
    int l = nodes.size();
    Tree* root = NULL;
    for(int i = 0;i < l;i++){
        root = insertion(root,nodes[i]);
    }
    vector<vector<int>> lot = bfs(root);

    for(int i = 0;i<lot.size();i++){
        for(int j = 0; j < lot[i].size();j++){
            cout << lot[i][j] << " ";
        }
    }
}