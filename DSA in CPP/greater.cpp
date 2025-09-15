#include <iostream>
using namespace std;

const int stacksize = 4;
struct stack
{
    int arr[stacksize];
    int top;
};

int top(stack &s)
{
    return s.top;
}
bool isfull(stack &s)
{
    if (s.top == stacksize - 1)
    {
        return true;
    }
    return false;
}
void push(stack &s, int value)
{
    if (isfull(s))
    {
        cout << "Stack is full" << endl;
    }
    else
        s.arr[++s.top] = value;
}
bool isempty(stack &s)
{
    if (s.top != -1)
    {
        return false;
    }
    return true;
}
int pop(stack &s)
{
    if (!isempty(s))
    {
        return s.arr[s.top--];
    }
    return 0;
}
void display(stack &s)
{
    for (int i = 0; i < stacksize; i++)
    {
        cout << s.arr[i] << " ";
    }
}

int factorial(stack &s,int no){
    if (no==1)
    {
        return 1;
    }
    return factorial(s,pop(s))*factorial(s,pop(s)-1);
}
int main()
{
    stack s;
    int n=4;

    for (int i = 1; i <= 4; i++)
    {
        push(s,i);
    }
    
cout<<factorial(s,n);
    // int arr[stacksize] = {4, 5, 2, 25};
    // stack s;
    // s.top = -1;
    // for (int i = 0; i < stacksize; i++)
    // {
    //     push(s, -1);
    // }
    // s.top = -1;
    // for (int i = 0; i < stacksize; i++)
    // {
    //     while (!isempty(s) && arr[i] > arr[s.top])
    //     {
    //         push(s, arr[i]);
    //         pop(s);
    //     }
    //     push(s, arr[i]);
    // }

    // display(s);

    return 0;
}