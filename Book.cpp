 #include <iostream>
 using namespace std;
 struct node
 {
    char name[20];
    int count;
    struct node *child[20];
 } *root;
 class trees
 {
 public:
    trees()
    {
        root = NULL;
    }
    void create()
    {
        root = new node();
        cout << "Enter book name: " << endl;
        cin >> root->name;
        cout << "Enter number of chapters : " << endl;
        cin >> root->count;
        for (int i = 0; i < root->count; i++)
        {
            root->child[i] = new node();
            cout << "Enter name of chapter "<<i+1<<" : "<< endl;
            cin >> root->child[i]->name;
            cout << "Enter number of sections : " << endl;
            cin >> root->child[i]->count;
            for (int j = 0; j < root->child[i]->count; j++)
            {
                root->child[i]->child[j] = new node();
                cout << "Enter name of section "<<j+1<<" : "<<endl;
                cin >> root->child[i]->child[j]->name;
                cout << "Enter number of subsections : " << endl;
                cin >> root->child[i]->child[j]->count;
                for (int k = 0; k < root->child[i]->child[j]->count; k++)
                {
                    root->child[i]->child[j]->child[k] = new node();
                    cout << "Enter name of subsection "<<k+1<<" : "<<endl;
                    cin >> root->child[i]->child[j]->child[k]->name;
                }
            }
        }
    }
    void display()
    {
        cout << "--------------------------------Book info-----------------------------"
 << endl;
        cout << "Name of book :" << root->name << endl;
        for (int i = 0; i < root->count; i++)
        {
            cout << "---------Chapter: " << i + 1 << "---------" << endl;
            cout << "  " << root->child[i]->name << endl;
            for (int j = 0; j < root->child[i]->count; j++)
            {
                cout << "    " << root->child[i]->child[j]->name << endl;
                for (int k = 0; k < root->child[i]->child[j]->count; k++)
                {
                    cout << "      " << root->child[i]->child[j]->child[k]->name << endl;
                }
            }
        }
    }
 };
 int main()

 {
    trees t;
    t.create();
    t.display();
    return 0;
 }