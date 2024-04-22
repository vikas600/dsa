#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;

int op, cnt = 0;

class node {
public:
    node *left;
    char word[50], mean[50];
    node *right;
};

class BT {
public:
    node *root;
    BT() {
        root = NULL;
    }
    void create();
    node *insert(node *, node *);
    void inorder(node *);
    void preorder(node *);
    void postorder(node *);
    void search(node *, char[]);
    void modify(node *, char[]);
    node *dit(node *, char[]);
    node *findmin(node *);
};

void BT::create() {
    int op;
    node *temp;
    do {
        temp = new node;
        cout << "Enter a word : ";
        cin >> temp->word;
        cout << "Enter a meaning : ";
        cin >> temp->mean;
        temp->left = temp->right = NULL;
        if (root == NULL)
            root = temp;
        else
            root = insert(root, temp);
        cout << "Want to insert again(1/0)? : ";
        cin >> op;
    } while (op == 1);
}

node *BT::insert(node *root, node *temp) {
    if (strcmp(temp->word, root->word) < 0) {
        if (root->left == NULL)
            root->left = temp;
        else
            insert(root->left, temp);
    } else {
        if (root->right == NULL)
            root->right = temp;
        else
            insert(root->right, temp);
    }
    return root;
}

void BT::inorder(node *temp) {
    if (temp != NULL) {
        inorder(temp->left);
        cout << temp->word << "->" << temp->mean << ", ";
        inorder(temp->right);
    }
}

void BT::preorder(node *temp) {
    if (temp != NULL) {
        cout << temp->word << "->" << temp->mean << ", ";
        preorder(temp->left);
        preorder(temp->right);
    }
}

void BT::postorder(node *temp) {
    if (temp != NULL) {
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->word << "->" << temp->mean << ", ";
    }
}

void BT::search(node *temp, char src[]) {
    if (temp != NULL) {
        if (strcmp(temp->word, src) == 0) {
            cout << "\nWord Found\n";
            cout << "Word: " << temp->word << endl;
            cout << "Meaning: " << temp->mean << endl;
            cnt++;
        } else {
            if (strcmp(src, temp->word) > 0)
                search(temp->right, src);
            else
                search(temp->left, src);
            cnt++;
        }
    } else {
        cout << "\nWord Not Found\n";
    }
    cout << "Total no. of Comparisons to search an element is: " << cnt << endl;
}

void BT::modify(node *temp, char src[]) {
    if (temp != NULL) {
        if (strcmp(temp->word, src) == 0) {
            cout << "\nWord Found!\n";
            cout << "\nEnter New Meaning of Word: ";
            cin >> temp->mean;
        } else {
            if ((strcmp(temp->word, src)) < 0)
                modify(temp->right, src);
            else if ((strcmp(temp->word, src)) > 0)
                modify(temp->left, src);
            else
                cout << "Word not found\n";
        }
    }
}

node *BT::dit(node *root, char src[]) {
    if (root != NULL) {
        if ((strcmp(root->word, src)) < 0)
            root->left = dit(root->left, src);
        else {
            if (root->left == NULL && root->right == NULL) {
                delete (root);
                root = NULL;
            } else if (root->left == NULL && root->right != NULL) {
                node *temp = root;
                root = root->right;
                strcpy(root->word, temp->word);
                strcpy(root->mean, temp->mean);
                temp->right = NULL;
                delete (root);
            } else if (root->right == NULL) {
                node *temp = root;
                root = root->left;
                strcpy(root->word, temp->word);
                strcpy(root->mean, temp->mean);
                temp->left = NULL;
                delete (root);
            } else {
                node *temp = findmin(root->right);
                strcpy(root->word, temp->word);
                strcpy(root->mean, temp->mean);
                root->right = dit(root->right, temp->word);
            }
        }
    }
    return root;
}

node *BT::findmin(node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

int main() {
    BT b;
    int op;
    char src[100];
    while (1) {
        cout << "\n\n1.Insert Binary Search Tree\n2.Display Inorder, Preorder, Postorder\n";
        cout << "3.Search Word\n4.Modify the meaning of word\n5.Delete word from dictionary\n6.Exit\n\nEnter your choice: ";
        cin >> op;
        switch (op) {
            case 1:
                b.create();
                break;
            case 2:
                cout << "\nInorder: ";
                b.inorder(b.root);
                cout << "\nPreorder: ";
                b.preorder(b.root);
                cout << "\nPostorder: ";
                b.postorder(b.root);
                cout << endl;
                break;
            case 3:
                cout << "\nEnter word want to search: ";
                cin >> src;
                b.search(b.root, src);
                break;
            case 4:
                cout << "\nEnter word want to modify: ";
                cin >> src;
                b.modify(b.root, src);
                break;
            case 5:
                cout << "\nEnter word you want to delete: ";
                cin >> src;
                b.dit(b.root, src);
                break;
            case 6:
                exit(0);
                break;
            default:
                cout << "\nInvalid option\n";
                break;
        }
    }
    return 0;
}
