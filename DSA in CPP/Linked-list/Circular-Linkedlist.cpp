
//*************** */ Circular linked list ********************
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *Next;
};
class circular
{
    Node *rear;
    Node *front;

public:
    circular()
    {
        rear = nullptr;
        front = nullptr;
    }
    void insertatRear(int n)
    {
        Node *ptr = new Node;
        ptr->data = n;
        if (rear == nullptr)
        {
            front = rear = ptr;
            ptr->Next = front;
        }
        else
        {
            rear->Next = ptr;
            rear = ptr;
            rear->Next = front;
        }
    }
    void insertatFront(int n)
    {
        Node *ptr = new Node;
        ptr->data = n;
        if (rear == nullptr)
        {
            cout << "cannot insert at front bcz Rear is empty" << endl;
            return;
        }
        else
        {
            ptr->Next = front;
            front = ptr;
            rear->Next = front;
        }
    }
    int removefront()
    {
        if (front == nullptr)
        {
            rear = nullptr;
            cout << "Queue is empty" << endl;
            return -1;
        }
        if (front == rear)
        {
            int temp = front->data;
            delete front;
            rear = front = nullptr;
            return temp;
        }

        Node *del = front;
        int temp = front->data;
        front = front->Next;
        rear->Next = front;
        delete del;
        return temp;
    }
    int removerear()
    {
        if (rear == nullptr)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        if (front == rear)
        {
            int temp = rear->data;
            delete rear;
            rear = front = nullptr;
            return temp;
        }

        Node *temp = front;
        while (temp->Next != rear)
        {
            temp = temp->Next;
        }
        Node *del = rear;
        int val = rear->data;
        rear = temp;
        rear->Next = front;
        delete del;
        return val;
    }
    void display(){
        if (rear == nullptr)
        {
            cout << "Queue is empty" << endl;
            return ;
        }
        Node* temp=front;
        do{
            cout<<temp->data<<" ";
            temp=temp->Next;
        }while (temp!=front);
        cout<<endl;
}
};

int main()
{
    circular c;
    c.insertatRear(34);
    c.insertatRear(54);
    c.insertatRear(64);
    c.insertatFront(14);
    c.display();
    c.removerear();
    c.display();
    c.removefront();
    c.removefront();
    c.display();
    return 0;
}