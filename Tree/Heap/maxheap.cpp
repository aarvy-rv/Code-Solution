#include <iostream>
#include <vector>
#include <queue>

struct Tree {
    int data;
    Tree* left;
    Tree* right;

    Tree(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to swap the data of two nodes
void swap(Tree* a, Tree* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Function to heapify the tree rooted at the given node
void heapify(Tree* root) {
    if (root == NULL)
        return;

    Tree* largest = root;

    if (root->left != NULL && root->left->data > largest->data) {
        largest = root->left;
    }

    if (root->right != NULL && root->right->data > largest->data) {
        largest = root->right;
    }

    if (largest != root) {
        swap(largest, root);
        heapify(largest);  // Recursively heapify the affected subtree
    }
}

// Function to insert a new node in the tree
Tree* insert(Tree* root, int data) {
    if (root == NULL) {
        return new Tree(data);
    }

    std::queue<Tree*> q;
    q.push(root);

    while (!q.empty()) {
        Tree* current = q.front();
        q.pop();

        if (current->left == NULL) {
            current->left = new Tree(data);
            heapify(root);  // Maintain heap property
            break;
        } else {
            q.push(current->left);
        }

        if (current->right == NULL) {
            current->right = new Tree(data);
            heapify(root);  // Maintain heap property
            break;
        } else {
            q.push(current->right);
        }
    }

    return root;
}

// Function to print the tree level by level
void printLevelOrder(Tree* root) {
    if (root == NULL)
        return;

    std::queue<Tree*> q;
    q.push(root);

    while (!q.empty()) {
        Tree* current = q.front();
        q.pop();
        std::cout << current->data << " ";

        if (current->left != NULL)
            q.push(current->left);
        if (current->right != NULL)
            q.push(current->right);
    }
}

int main() {
    std::vector<int> elementList{14, 34, 12, 11, 25, 8, 35};

    Tree* root = NULL;

    for (int i = 0; i < elementList.size(); i++) {
        root = insert(root, elementList[i]);
    }

    std::cout << "Max Heap Tree Level Order: ";
    printLevelOrder(root);
    std::cout << std::endl;

    return 0;
}
