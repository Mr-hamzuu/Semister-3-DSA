#include<iostream>
using namespace std;

const int stack_size=5;
struct book
{
    string name;
    int price;
};

struct stack
{
    book arr[stack_size];
    int top;
};

void push(stack &s,book &b){
    ++s.top;
    s.arr[s.top].name=b.name;
    s.arr[s.top].price=b.price;
}
void display(stack &s){
    for (int i = 0; i <=s.top; i++)
    {
       cout<<"Book name : "<<s.arr[i].name<<endl;
       cout<<"Book price : "<<s.arr[i].price<<endl;
    }
    
}
int main()
{
    stack s;
    s.top=-1;
    book b;
    b.name="all is well";
    b.price=5000;
    push(s,b);
    display(s);
    return 0;
}