#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> extractOperand(stack<int> *operand){
        int op1 = operand->top();
        operand->pop();
        int op2 = operand->top();
        operand->pop();

        vector<int> ops;
        ops.push_back(op2);
        ops.push_back(op1);
        return ops;

    }
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;
        vector<int> elements;
        int lengthOfTokens = tokens.size();
        
        for(int index = 0; index<lengthOfTokens; index++){
            if(tokens[index]=="+"){
                elements=extractOperand(&operands);
                operands.push(elements[0]+elements[1]);
            }
            else if(tokens[index]=="-"){
                elements=extractOperand(&operands);
                operands.push(elements[0]-elements[1]);
            }
            else if(tokens[index]=="/"){
                elements=extractOperand(&operands);
                operands.push(elements[0]/elements[1]);
            } 
            else if(tokens[index]=="*"){
                elements=extractOperand(&operands);
                operands.push(elements[0]*elements[1]);
            }
            else{
                operands.push(stoi(tokens[index]));
            }
        }
        return operands.top();
        
    }
};