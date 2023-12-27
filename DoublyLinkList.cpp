#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node* prev;

    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node(){
        int value= this->val;
        if(this-> next != NULL || this->prev != NULL){
            this->next=NULL;
            this->prev=NULL;
        }
        cout<<"Deleting Node with value "<<value<<"\n";
    }
};

void insertAtHead(Node* &head,Node* &tail,int val){

    Node* node = new Node(val);

    if(head == NULL){
        head = node;
        tail = node;
    }
    else
    {
        node->next = head;
        head->prev = node;
        head = node;
    }
}
void insertAtTail(Node* &head,Node* &tail,int val){
    Node* node = new Node(val);
        if(tail == NULL){
        head = node;
        tail = node;
    }
    else{
    tail->next = node;
    node->prev = tail;
    tail = node;
    }
}
void insertAtKthPosition(Node* &head,Node* &tail,int k,int val){

    
    Node* node = new Node (val);

    if(k == 0){
        insertAtHead(head,tail,val);
        return;
    }
    
    Node* temp = head;
    int i = 0;
    while(i++<k-1){
        temp = temp->next;
    }
    if(temp->next == NULL)
    {
        insertAtTail(head,tail,val);
        return;
    }
    node->next = temp->next;
    temp->next->prev = node;
    temp->next = node;
    node->prev =temp;}

void deleteAtHead(Node* &head){

    Node* temp = head;
    head = temp->next;
    head->prev =NULL;

    temp->next = NULL;
    delete(temp);

}

void deleteAtTail(Node* &tail){
    
     Node* temp = tail;
    tail = tail->prev;

    if(tail!=NULL){
        tail->next = NULL;
    }
    temp->prev = NULL;
   delete(temp);
}

void deleteNode(Node* &head,Node* &tail,int k){
    if(k==0){
        deleteAtHead(head);
        return;
    }
    Node* curr =head;
    Node* prev = NULL;
    int i = 0;
    while(i<k){
        prev = curr;
        curr = curr->next;
        i++;
    }
    if(curr->next==NULL){
        deleteAtTail(tail);
        return;
    }

    prev->next = curr->next;
    curr->next->prev = prev;
    curr->next =NULL;
    curr->prev = NULL;
    delete(curr);

}
void printFromHead(Node* &head){
    Node* temp = head;
    cout << "From Head: ";
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
        }
        cout<<"\n";
}
void printFromTail(Node* &tail){
    Node* temp = tail;
    cout<<"From Tail: ";
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->prev;
    }
    cout<<"\n";
}
void printHeadTailValue(Node* &head,Node* &tail){

    cout<<"Head Value: "<< head->val<<"\n";
    cout<<"Tail Value: "<<tail->val<<"\n";
}

int main(){
    Node* node1 = new Node(40);
    Node* head = NULL;//node1;
    Node* tail = NULL;//node1;

    insertAtHead(head,tail,30);
    printFromHead(head);
    printFromTail(tail);

    insertAtHead(head,tail,20);
    printFromHead(head);
    printFromTail(tail);

    insertAtHead(head,tail,10);
    printFromHead(head);
    printFromTail(tail);

    insertAtTail(head,tail,50);
    printFromHead(head);
    printFromTail(tail);

    
    insertAtTail(head,tail,60);
    printFromHead(head);
    printFromTail(tail);

    
    insertAtTail(head,tail,70);
    printFromHead(head);
    printFromTail(tail);

    insertAtKthPosition(head,tail,1,15);
    printFromHead(head);
    printFromTail(tail);

    insertAtKthPosition(head,tail,0,5);
    printFromHead(head);
    printFromTail(tail);
    printHeadTailValue(head,tail);

    insertAtKthPosition(head,tail,8,80);
    printFromHead(head);
    printFromTail(tail);
    printHeadTailValue(head,tail);

    
    deleteAtHead(head);
    printFromHead(head);
    printFromTail(tail);
    printHeadTailValue(head,tail);

    
    deleteAtTail(tail);
    printFromHead(head);
    printFromTail(tail); 
    printHeadTailValue(head,tail);

    
   deleteNode(head,tail,0);
    printFromHead(head);
    printFromTail(tail);

    deleteNode(head,tail,3);
    printFromHead(head);
    printFromTail(tail);

    deleteNode(head,tail,4);
    printFromHead(head);
    printFromTail(tail); 



}