#include <iostream>
using namespace std;

struct stack
{
    int arr[5];
    int top;
};

void push(stack &s, int value)
{
    if (s.top < 4)
    {
        s.arr[++s.top] = value;
    }
    else
    {
        cout << "Stack is full" << endl;
    }
}
int pop(stack &s)
{
    if (s.top == -1)
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return s.arr[s.top--];
}

void display(const stack &s)
{
    for (int i = 0; i <= s.top; i++)
    {
        cout << s.arr[i] << " ";
    }
}

int main()
{
    stack s;
    s.top = -1;
    push(s, 3);
    push(s, 6);
    push(s, 8);
    push(s, 9);
    push(s, 2);
    display(s);
    cout << endl;
    pop(s);
    display(s);
  
    return 0;
}