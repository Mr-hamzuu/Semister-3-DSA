#include <iostream>
using namespace std;
const int stack_size = 5;
struct stack
{
    int arr[stack_size];
    int top;
};

bool isfull(stack &s)
{
    if (s.top < stack_size - 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void push(stack &s, int value)
{
    if (!isfull(s))
    {
        s.arr[++s.top] = value;
    }
    else
    {
        cout << "Stack is full" << endl;
    }
}
bool isempty(stack &s)
{
    if (s.top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void pop(stack &s, int idx)
{
    if (isempty(s))
    {
        cout << "Stack is empty" << endl;
        return;
    }
    for (int i = idx; i <= s.top; i++)
    {
        int temp = s.arr[i];
        s.arr[i] = s.arr[i + 1];
        s.arr[i + 1] = temp;
    }
    s.top--;
}


void display(const stack &s)
{
    for (int i = 0; i <= s.top; i++)
    {
        cout << s.arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    stack s;
    s.top = -1;
    do
    {
        char n;
        cout << "press P to push\nPress R to pop \nPress D to Display\nPress E to exit" << endl;
        cin >> n;
        switch (n)
        {
        case 'P':
            int value;
            cout << "Enter the value ";
            cin >> value;
            push(s, value);
            break;
        case 'R':
            int idx;
            cout << "Enter the index : ";
            cin >> idx;
            pop(s, idx);
            break;
        case 'D':

            display(s);
            break;

        case 'E':
            exit(0);
            break;

        default:
            break;
        }
    } while (true);

    return 0;
}