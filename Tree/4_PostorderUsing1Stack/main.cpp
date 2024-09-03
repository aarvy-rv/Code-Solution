#include<iostream>
#include<vector>
#include <stack>
using namespace std;

struct TreeNode{

    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val = val;
        this->left = this->right = NULL;
    }

};

class Traversal{
    public:

    vector<int> postOrderTraversalUsingOneStack(TreeNode* root){

        TreeNode* curr = root;
        vector<int> postorder;

        stack<TreeNode*> st;

        while(curr != NULL || !st.empty()){
            if(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }
            else{
                TreeNode* temp = st.top()->right;
                if(temp == NULL){
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->val);
                    while(!st.empty() && st.top()->right == temp){
                        temp = st.top();
                        st.pop();
                        postorder.push_back(temp->val);
                    }
                }
                else{
                    curr=temp;
                }
            }
        }
        return postorder;
    }

};