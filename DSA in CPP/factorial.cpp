#include <iostream>
using namespace std;

const int stacksize = 6;
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

int factorial(stack &s, int no)
{
    for (int i = no; i > 0; i--)
    {
        push(s, i);
    }

    int result = 1;
    for (int i = s.top; i > 0; i--)
    {
        int op1 = pop(s);
        int op2 = pop(s);
        result = op1 * op2;
        push(s, result);
    }

    // while (!isempty(s))
    // {
    //     result*=pop(s);

    // }

    return result;
}

// reverse
void reverse(stack &s, int n)
{
    for (int i = 0; i < 5; i++)
    {
        push(s, i);
    }
    while (!isempty(s))
    {
        cout << pop(s) << " ";
    }
}

// next greater no
void nextgreater(stack &s, int n)
{
    int arr[5] = {2, 5, 3, 55, 99};
    int result[5];
    for (int i = n - 1; i >= 0; i--)
    {

        while (!isempty(s) && arr[i] >= s.arr[s.top])
        {
            pop(s);
        }
        if (isempty(s))
        {
            result[i] = -1;
        }
        else
        {
            result[i] = s.arr[s.top];
        }
        push(s, arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
}
int main()
{
    stack s;
    s.top = -1;

    int n;
    cout << "Enter a no : ";
    cin >> n;
    // cout << factorial(s, n);
    // reverse(s, n);
    nextgreater(s, n);

    return 0;
}