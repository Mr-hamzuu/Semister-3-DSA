// #include <iostream>
// using namespace std;

// struct Node
// {
//     int data;
//     Node *next;
// };

// class Queue
// {
//     Node *front;
//     Node *rear;

// public:
//     Queue()
//     {
//         front = nullptr;
//         rear = nullptr;
//     }
//     void insert(int n)
//     {
//         Node *newnode = new Node;
//         newnode->data = n;
//         newnode->next = nullptr;
//         if (rear == nullptr)
//         {
//             front = newnode;
//         }
//         else
//         {
//             rear->next = newnode;
//         }

//         rear = newnode;
//     }
//     int remove()
//     {
//         if (rear == nullptr)
//         {
//             cout << "Stacklist is empty" << endl;
//         }
//         else
//         {
//             int temp = front->data;
//             Node *del = front;

//             if (front->next == nullptr)
//             {
//                 rear = nullptr;
//             }
//             else
//             {

//                 front = del->next;
//                 delete del;
//                 return temp;
//             }
//         }
//         return -1;
//     }
//     void display()
//     {
//         if (rear == nullptr)
//         {
//             cout << "Stacklist is empty" << endl;
//         }
//         else
//         {
//             Node *temp = front;
//             while (temp != nullptr)
//             {
//                 cout << temp->data << " ";
//                 temp = temp->next;
//             }
//         }
//     }
// };
// int main()
// {
//     Queue l;
//     l.insert(66);
//     l.insert(36);
//     l.insert(96);
//     l.insert(76);
//     l.insert(16);
//     cout << l.remove() << endl;
//     l.display();
//     return 0;
// }

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Queue
{
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }
    void insert(int x)
    {
        Node *ptr = new Node;
        ptr->data = x;
        if (rear == NULL)
            ptr->next = ptr;
        else
        {
            ptr->next = rear->next;
            rear->next = ptr;
        }
        rear = ptr;
    }
    int remove()
    {

        if (rear == NULL)
        {
            cout << "\nlist empty\n";
            return 0;
        }
        else
        {

            int temp = rear->next->data;
            Node *ptr = rear->next;
            if (rear == rear->next)
                rear = NULL;
            else
                rear->next = rear->next->next;
            delete ptr;
            return temp;
        }
    }
    void display()
    {
        if (rear == nullptr)
        {
            cout << "Stacklist is empty" << endl;
        }
        else
        {
            Node *temp = front;
            while (temp != nullptr)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
    }
};
int main()
{
    Queue l;
    l.insert(66);
    l.insert(36);
    l.insert(96);
    l.insert(76);
    l.insert(16);
    cout << l.remove() << endl;
    cout << l.remove() << endl;
    l.display();
    return 0;
}