#include <iostream>
using namespace std;

struct Node
{
    Node *prev;
    int data;
    Node *next;
};
class Doubly_LinkedList
{
    Node *head;

public:
    Doubly_LinkedList()
    {
        head = NULL;
    }
    void insertAtHead(int n)
    {
        Node *temp = new Node;
        temp->data = n;
        temp->prev = NULL;
        temp->next = head;
        if (head != NULL)
        {
            head->prev = temp;
        }
        head = temp;
    }
    void insertAtTail(int n)
    {

        Node *newnode = new Node;
        newnode->data = n;
        Node *temp = head;
        if (head == NULL)
        {
            newnode->next = NULL;
            head = newnode;
            return;
        }

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        newnode->prev = temp;
        newnode->next = NULL;
        temp->next = newnode;
    }
    void insertAtPosition(int value, int position)
    {
        if (position == 1)
        {
            insertAtHead(value);
            return;
        }
        Node *temp = head;
        int c = 1;
        while (c < position - 1)
        {
            temp = temp->next;
            c++;
        }
        Node *node = new Node;
        node->data = value;
        node->next = temp->next;
        if (temp->next != NULL)
        {
            temp->next->prev = node;
        }
        node->prev = temp;
        temp->next = node;
    }
    void remove(int value)
    {
        if (head == NULL)
        {
            cout << "List is Empty" << endl;
            return;
        }

        Node *temp = head;
        if (temp->data == value)
        {
            head = head->next;
            if (head != NULL)
            {
                head->prev = NULL;
            }
            delete temp;
            return;
        }

        while (temp != NULL && temp->data != value)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "Value not found in the list!" << endl;
            return;
        }

        if (temp->next != nullptr)
        {
            temp->next->prev = temp->prev;
        }

        if (temp->prev != nullptr)
        {
            temp->prev->next = temp->next;
        }
        delete temp;
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    Doubly_LinkedList l;
    cout << "Insert at Head : ";
    l.insertAtHead(23);
    l.insertAtHead(44);
    l.insertAtHead(94);
    l.insertAtHead(14);
    l.display();
    cout << endl;
    cout << "Insert at Tail : ";
    l.insertAtTail(65);
    l.insertAtTail(75);
    l.insertAtTail(85);
    l.display();
    cout << endl;
    cout << "Insert at Position : ";
    l.insertAtPosition(122, 2);
    l.insertAtPosition(99, 1);
    l.display();
    cout << endl;
    cout << "Delete Value : ";
    l.remove(94);
    l.display();
    cout << endl;
    cout << "Delete Value : ";
    l.remove(122);
    l.display();
    return 0;
}