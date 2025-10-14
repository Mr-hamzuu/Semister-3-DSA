#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    void insert(int val)
    {
        Node *node1 = new Node;
        node1->data = val;
        node1->next = NULL;
        if (head == NULL)
        {
            head = node1;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = node1;
        }
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << "[Data:" << temp->data << "] --> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main()
{
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.display();
    return 0;
}