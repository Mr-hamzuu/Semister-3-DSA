
//******************* */ STACK Linked list ******************************
#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stacklist{
    Node *top;
    public:
    Stacklist(){
        top=nullptr;
    }
    void push(int n){
        Node *newnode=new Node;
        newnode->data=n;
        newnode->next=top;
        top=newnode;
    }
    int pop(){
        if (top==nullptr)
        {
            cout<<"Stacklist is empty"<<endl;
            return -1;
        }
        else{
            int temp=top->data;
            Node *del=top;
            top=top->next;
            delete del;
            return temp;
        }
    }
    void display(){
        if (top==nullptr)
        {
            cout<<"Stacklist is empty"<<endl;
 return;
        }
        else{
            Node *temp=top;
            while (temp->next!=nullptr)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }  
    }
};
int main()
{
    Stacklist l;
    l.push(66);
    l.push(36);
    l.push(96);
    l.push(76);
    l.push(16);
    cout<<l.pop()<<endl;
    l.display();
    return 0;
}


