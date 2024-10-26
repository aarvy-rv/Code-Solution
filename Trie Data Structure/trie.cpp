#include<iostream>
using namespace std;

struct Node{
    Node* letter[26];
    bool flag;

    Node(){
        flag = false;
        for (int i = 0; i < 26; ++i) {
            letter[i] = nullptr;  
        }
    }
    
    bool isCharAvailable(char index){
        if(letter[index-'a'] == NULL)
            return false;

        return true;
    }

    void createReference(char ch,Node* node){
        letter[ch-'a'] = node;
    }

    Node* getReference(char ch){
        return letter[ch-'a'];
    }

    void setEnd(){
        this->flag =true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie{
    public:
        Node* root;

    Trie(){
        this->root = new Node(); 
    }

    ~Trie() {
        deleteNode(root);  // Call to delete all nodes
    }

    void deleteNode(Node* node) {
        for (int i = 0; i < 26; ++i) {
            if (node->letter[i]) {
                deleteNode(node->letter[i]);
            }
        }
        delete node;
    }

    void insert(string word){
        Node* node = root;
        int len = word.length();
        for(int i = 0; i < len;i++){
            if(!node->isCharAvailable(word[i])){
                node->createReference(word[i],new Node());
            }
            node  = node->getReference(word[i]);
        }
        node->setEnd();
        cout << word+" inserted successfully!\n";
    }

    bool search(string word){
        Node* node = root;
        int len = word.length();
        for(int i = 0;i<len;i++){
            node = node->getReference(word[i]);
            if(node == nullptr)
                return false;
        }
        return node->isEnd();
    }

    bool startsWith(string prefix){
        int len = prefix.length();
        Node* node = root;
        for(int i = 0; i < len; i++){
             node = node->getReference(prefix[i]);
            if(node == nullptr)
                return false;
        }
        return true;
    }


};

int main(){
    Trie* instance = new Trie();
    instance->insert("app");
    instance->insert("apple");
    cout << " Is the arc present: " << instance->search("arc") << "\n";
    cout << " Is the app present: " << instance->search("app") << "\n";
    cout << " Is the apple present: " << instance->search("apple") << "\n";
    instance->insert("bat");
    instance->insert("battle");
    cout <<"Is hill a prefrix of any word in Trie: "<<instance->startsWith("hill")<<"\n";
    cout <<"Is ap a prefrix of any word in Trie: "<<instance->startsWith("ap")<<"\n";
    cout <<"Is app a prefrix of any word in Trie: "<<instance->startsWith("app")<<"\n";
    cout <<"Is ba a prefrix of any word in Trie: "<<instance->startsWith("ba")<<"\n";
    cout <<"Is bal a prefrix of any word in Trie: "<<instance->startsWith("bal")<<"\n";

    delete instance;
    
}