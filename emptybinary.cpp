#include<iostream>
using namespace std;

class Node {
public:
    int key;
    Node *ln, *rn;
};

class Tree {
public:
    Node *root;
    
    Node *createTree(int key) {
        root = new Node();
        root->key = key;
        root->ln = NULL;
        root->rn = NULL;
        return root;
    }
    
    void insertNode(int key, Node *root) {
        Node *node = new Node();
        node->key = key;
        if (root->key > key) {
            if (root->ln == NULL) {
                root->ln = node;
            } else {
                insertNode(key, root->ln);
            }
        } else if (root->key < key) {
            if (root->rn == NULL) {
                root->rn = node;
            } else {
                insertNode(key, root->rn);
            }
        } else {
            cout << "No duplicate keys are allowed";
        }
    }
    
    void searchNode(int searchkey, Node *root) {
        if (root == NULL) {
            cout << "No tree present";
            return;
        }
        
        if (root->key == searchkey) {
            cout << "Key found!";
        } else if (root->key > searchkey) {
            if (root->ln == NULL) {
                cout << "Key is not present in the tree";
            } else {
                searchNode(searchkey, root->ln);
            }
        } else if (root->key < searchkey) {
            if (root->rn == NULL) {
                cout << "Key is not present in the tree";
            } else {
                searchNode(searchkey, root->rn);
            }
        }
    }
    
    void displayInorder(Node *root) {
        if (root != NULL) {
            displayInorder(root->ln);
            cout << root->key << "\n";
            displayInorder(root->rn);
        }
    }
    
    void displaymin(Node *root) {
        while (root->ln != NULL) {
            root = root->ln;
        }
        cout << "\n Minimum number is: " << root->key;
    }
    
    int longestpath(Node *root) {
        if (root == NULL) {
            return 0;
        }

        int lctr = longestpath(root->ln);
        int rctr = longestpath(root->rn);

        if (lctr > rctr) {
            return (lctr + 1);
        } else {
            return (rctr + 1);
        }
    }
    
    Node *swapNodes(Node *root) {
        Node *temp;
        if (root == NULL) {
            return NULL;
        }
        temp = root->ln;
        root->ln = root->rn;
        root->rn = temp;
        swapNodes(root->ln);
        swapNodes(root->rn);
        return root;
    }
};

int main() {
    int choice, flag = 0;
    int key, searchkey;
    Tree t1;
    Node *root = nullptr;
    do {
        cout << "\n1. Enter numbers \n2. Display \n3. Display min valued Node\n4. Swap left and right Nodes \n5. Search \n6. No. of Nodes in longest path \n7. Exit \n Enter your choice";

        cin >> choice;
        switch (choice) {
            case 1:
                cout << "\nEnter the number:";
                cin >> key;
                if (flag == 0) {
                    root = t1.createTree(key);
                    flag = 1;
                } else {
                    t1.insertNode(key, root);
                }
                break;

            case 2:
                t1.displayInorder(root);
                break;

            case 3:
                t1.displaymin(root);
                break;

            case 4:
                root = t1.swapNodes(root);
                cout << "Swapped! The new list is:";
                t1.displayInorder(root);
                break;

            case 5:
                cout << "\nEnter the key you want to search:";
                cin >> searchkey;
                t1.searchNode(searchkey, root);
                break;

            case 6:
                cout << "The height of the tree or the longest path is:" << t1.longestpath(root);
                break;

            case 7: 
                exit(0);
        }
    } while (choice != 7);
    return 0;
}
