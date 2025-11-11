// #include <iostream>
// using namespace std;

// struct Node
// {
//     int data;
//     Node *next;
// };
// class LinkedList
// {
//     Node *head;

// public:
//     LinkedList()
//     {
//         head = NULL;
//     }
//     void insert(int val)
//     {
//         Node *node1 = new Node;
//         node1->data = val;
//         node1->next = NULL;
//         if (head == NULL)
//         {
//             head = node1;
//         }
//         else
//         {
//             Node *temp = head;
//             while (temp->next != NULL)
//             {
//                 temp = temp->next;
//             }
//             temp->next = node1;
//         }
//     }
//     void display()
//     {
//         Node *temp = head;
//         while (temp != NULL)
//         {
//             cout << "[Data:" << temp->data << "] --> ";
//             temp = temp->next;
//         }
//         cout << "NULL" << endl;
//     }
// };
// int main()
// {
//     LinkedList list;
//     list.insert(10);
//     list.insert(20);
//     list.insert(30);
//     list.insert(40);
//     list.display();
//     return 0;
// }


//******************************** */ Doubly Linked list **************************************
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
class Linked_list
{
    Node *head;
    Node *Tail;

public:
    Linked_list()
    {
        head = NULL;
    }
    void push_back(int n)
    {
        Node *newnode = new Node;
        newnode->data = n;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            Node *Temp = head;
            while (Temp->next != NULL)
            {
                Temp = Temp->next;
            }
            Temp->next = newnode;
        }
    }
    void push_front(int n)
    {
        Node *temp = new Node;
        temp->data = n;
        temp->next = head;
        head = temp;
    }
    void insert(int value, int idx)
    {
        if (idx == 1)
        {
            push_front(value);
            return;
        }

        Node *temp = head;
        int c = 1;
        while (c < idx - 1)
        {
            temp = temp->next;
            c++;
        }

        Node *newnode = new Node;
        newnode->data = value;
        if (temp == NULL)
        {
            cout << "Index out of bond" << endl;
            delete newnode;
            return;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    void remove(int n)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head->data == n)
        {
            Node *Temp = head;

            head = head->next;
            delete Temp;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL && temp->next->data != n)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            cout << "Value Not Found" << endl;
        }
        else
        {
            Node *del = temp->next;
            temp->next = del->next;
            delete del;
        }
    }
    void display()
    {
        Node *Temp = head;
        while (Temp->next != NULL)
        {
            cout << "[" << Temp->data << "](Next)-> ";
            Temp = Temp->next;
        }
        cout << "[" << Temp->data << "](Next)-> NULL ";
          cout << endl;
    }
};
int main()
{
    Linked_list l;
    l.push_back(3);
    l.push_back(6);
    l.push_back(5);
    l.push_back(9);
    l.push_back(2);
    cout << "\033[1;33mInsert From Back : \033[0m";
    l.display();
  
    l.push_front(55);
    l.push_front(3);
    l.push_front(5);
    cout << "\033[1;33mInsert From Front : \033[0m";
    l.display();
   
    cout << "\033[1;33mInsert At Position : \033[0m";
    l.insert(23, 9);
    l.display();
   
    cout << "\033[1;33mRemove : \033[0m";
    l.remove(2);
    l.display();
    return 0;
}