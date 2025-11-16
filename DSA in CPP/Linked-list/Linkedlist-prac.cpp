// #include<iostream>
// using namespace std;

// struct Node
// {
//     int data;
//     Node* next;
// };

// class linkedlist{
//     Node* rear;
//     public:
//     linkedlist(){
//         rear=nullptr;
//     }
//     void push(int n){
//         Node* ptr=new Node;
//         ptr->data=n;
//         ptr->next=rear;
//         rear=ptr;
//     }
//     int pop(){
//         if (rear==nullptr)
//         {
//             cout<<"stack is empty"<<endl;
//             return -1;
//         }
//         Node* del=new Node;
//         int temp=rear->data;
//         del=rear;
//         rear=rear->next;
//         delete del;
//         return temp;
//     }
//     void display(){
//         Node* temp=rear;
//         while (temp!=nullptr)
//         {
//             cout<<temp->data<<" ";
//             temp=temp->next;
//         }
        
//     }

// };
// int main()
// {
//     linkedlist l;
//     l.push(34);
//     l.push(66);
//     l.push(69);
//     l.push(61);
//     l.display();
//     l.pop();
//     cout<<endl;
//     l.display();
//     return 0;
// }


// *************************** Queue linkedlist *****************************
// #include<iostream>
// using namespace std;

// struct Node
// {
//     int data;
//     Node* Next;
// };
// class queue{
//     Node* front;
//     Node* rear;
//     public:
//     queue(){
//         front=nullptr;
//         rear=nullptr;
//     }
//     void push(int n){
//         Node* ptr=new Node;
//         ptr->data=n;
//         if (rear==nullptr)
//         {
//             front=ptr;
//         }
//         else{
//             rear->Next=ptr;
//         }
//         rear=ptr;  
//         rear->Next=nullptr;
//     }
//     int pop(){
//         if (rear==nullptr)
//         {
//             cout<<"Queue is empty"<<endl;
//             return -1;
//         }
//         else{
//             int temp=front->data;
//             Node* del=front;
//             if (front->Next==nullptr)
//             {
//                 rear=nullptr;
//             }
//             else{

//                 front=front->Next;
//                 delete del;
//                 return temp;
//             }
//         }
//         return -1;
//     }
//     void display(){
//         if (rear==nullptr)
//         {
//             cout<<"Queue is empty"<<endl;
//             return; 
//         }
//         Node *temp=front;
//         while (temp!=nullptr)
//         {
//             cout<<temp->data<<" ";
//             temp=temp->Next;
//         }
//         cout<<endl;
//     }
// };
// int main()
// {
//     queue q;
//     q.push(45);
//     q.push(65);
//     q.push(85);
//     q.push(95);
//     q.push(75);
//     q.display();
//     q.pop();
//     q.pop();
//     q.pop();
//     q.pop();
    
//     q.display();
//     return 0;
// }



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