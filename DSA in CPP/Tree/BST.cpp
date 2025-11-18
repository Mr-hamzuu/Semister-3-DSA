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
    cout<<endl;
    b.displayInorder(n);
    cout<<endl;
    b.displayPostorder(n);

    return 0;
}