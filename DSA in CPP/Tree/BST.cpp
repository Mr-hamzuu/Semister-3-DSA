#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
class BST
{
private:
    Node *root;

public:
    BST()
    {
        root = nullptr;
    }
    void insert(int x)
    {
        Node *ptr = new Node;
        ptr->data = x;
        ptr->left = nullptr;
        ptr->right = nullptr;
        if (root == nullptr)
        {
            root = ptr;
            return;
        }
        Node *curr = root;
        Node *parent = nullptr;

        while (curr != nullptr)
        {
            parent = curr;
            if (x < curr->data)
                curr = curr->left;
            else
                curr = curr->right;
        }

        if (x < parent->data)
            parent->left = ptr;
        else
            parent->right = ptr;
    }

    void displayPreorder(Node *temp)
    {
        if (temp == nullptr)
            return;

        cout << temp->data << " ";
        displayPreorder(temp->left);
        displayPreorder(temp->right);
    }
    void displayInorder(Node *temp)
    {
        if (temp == nullptr)
            return;

        displayInorder(temp->left);
        cout << temp->data << " ";
        displayInorder(temp->right);
    }
    void displayPostorder(Node *temp)
    {
        if (temp == nullptr)
            return;

        displayPostorder(temp->left);
        displayPostorder(temp->right);
        cout << temp->data << " ";
    }
    bool search(int x)
    {
        if (root == nullptr)
        {
            cout << "Tree is empty" << endl;
            return false;
        }
        Node *temp = root;
        while (temp != nullptr)
        {
            if (temp->data == x)
            {
                return true;
            }
            if (x < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        return false;
    }
    int largestvalue(Node *temp)
    {
        while (temp->right != nullptr)
        {
            temp = temp->right;
        }
        return temp->data;
    }
    int smallestvalue(Node *temp)
    {
        while (temp->left != nullptr)
        {
            temp = temp->left;
        }
        return temp->data;
    }
    
    Node* deletevalue(Node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->data) {
        root->left = deletevalue(root->left, key);
    }
    else if (key > root->data) {
        root->right = deletevalue(root->right, key);
    }
    else {  
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        
        root->data = temp->data;
        root->right = deletevalue(root->right, temp->data); 
    }
    return root;
}
    Node *getRoot()
    {
        return root;
    }
};

int main()
{
    BST b;
    b.insert(45);
    b.insert(25);
    b.insert(15);
    b.insert(35);
    b.insert(65);
    b.insert(75);
    Node *n = b.getRoot();
    b.displayPreorder(n);
    cout << endl;
    b.displayInorder(n);
    cout << endl;
    b.displayPostorder(n);
    cout << endl;
    // search value in Tree
    if (b.search(5))
    {
        cout << "Value found" << endl;
    }
    else
        cout << "Value Not found" << endl;
    cout << b.largestvalue(n) << endl;
    cout << b.smallestvalue(n) << endl;
    b.deletevalue(n,65);
    b.displayInorder(n);
    return 0;
}