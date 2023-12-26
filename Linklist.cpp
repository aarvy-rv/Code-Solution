#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* next;

        Node(int val){
            this->val = val;
            this->next = NULL;
        }
        ~Node(){
            int value = this->val;
            if(this->next != NULL){
                this->next =NULL;
                 delete next;
            }
            cout<<"Deleting node with the value " << value <<"\n";
        }
};

void insertAtHead(Node* &head,int val){
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    
}
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}
void insertAtTail(Node* &tail,int val){

    Node* newNode = new Node(val);
    tail-> next = newNode;
    tail = newNode;

}

void insertAtKthIndex(Node* &head,Node* &tail,int k,int val){

    if(k == 0){
        insertAtHead(head,val);
        return;
    }
    Node* newNode = new Node(val);
    Node* temp =head;
    int i = 0;
    while(i < k-1){
        temp = temp->next;
        i++;
    }
    if(temp->next == NULL){
        insertAtTail(tail,val);
        return;
    }
    newNode -> next = temp->next;
    temp->next = newNode;
}

void deleteNode(Node* &head,Node* &tail,int position){
    if(position == 0){
        Node * temp = head;
        head = temp->next;
        temp->next =NULL;
        delete(temp);
    }
    else{
        Node* curr = head;
        Node* prev = NULL;
        int i=0;
        while( i < position){
            prev = curr;
            curr = curr->next;
            i++;
        }
        if(curr->next == NULL)
            tail = prev;
        prev->next = curr->next;
      //  curr->next = NULL;
        delete(curr);
    }
}

void printHeadTailValue(Node* &head,Node* &tail){
    cout << "Value at head: "<<head->val<<"\n";
    cout<< "Value at tail: "<< tail->val<<"\n";
}


int main(){

    Node* node = new Node(10);
    Node* head = node;
    Node* tail = node;

    print(head);
    insertAtHead(head,20);
    print(head);

    insertAtHead(head,30);
    print(head);

    insertAtTail(tail,40);
    print(head);

    insertAtKthIndex(head,tail,1,50);
    print(head);

    insertAtKthIndex(head,tail,4,0);
    print(head);

    insertAtKthIndex(head,tail,6,90);
    print(head);
    printHeadTailValue(head,tail);

    deleteNode(head,tail,1);
    print(head);

    deleteNode(head,tail,5);
    print(head);
    printHeadTailValue(head,tail);
    
    deleteNode(head,tail,2);
    print(head);

    deleteNode(head,tail,0);
    print(head);
    printHeadTailValue(head,tail);

   

}