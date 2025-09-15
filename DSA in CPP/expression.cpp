#include <iostream>
using namespace std;
const int arr_size = 20;
struct stack
{
    char arr[arr_size];
    int top;
};

bool isfull(stack &s)
{
    if (s.top == arr_size - 1)
        return true;
    else
        return false;
}
void push(stack &s, char value)
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
        return true;
    else
        return false;
}
char pop(stack &s)
{
    if (!isempty(s))
        return s.arr[s.top--];
    else
    {
        cout << "Stack is empty";
        return '\0';
    }
}

char stackTop(stack &s)
{
    return s.arr[s.top];
}
int precedence(char s)
{
    if (s == '+' || s == '-')
        return 1;
    else if (s == '*' || s == '/')
        return 2;
    return 0;
}


int main()
{
    stack s;
    stack s2;
    s.top = -1;
    s2.top = -1;
    bool valid = true;
    string exp;
    cout << "Enter the Expression :";
    getline(cin, exp);
    for (int i = 0; i < exp.length(); i++)
    {
        char symbol = exp[i];
        if (symbol == '(' || symbol == '$')
        {
            push(s2, symbol);
        }
        else
        {
            if ((symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z'))
            {
                push(s, symbol);
            }
            else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
            {
                while (!isempty(s2) && precedence(stackTop(s2)) >= precedence(symbol))
                {
                    push(s, pop(s2));
                }
                push(s2, symbol);
            }
            else if (symbol == ')')
            {
                while (!isempty(s2) && stackTop(s2) != '(')
                {
                    push(s, pop(s2));
                }
                if (isempty(s2))
                {
                    valid = false;
                }
                else
                {
                    pop(s2);
                }
            }
        }
    }

    while (!isempty(s2))
    {
        if (stackTop(s2) == '(')
        {
            valid = false;
            pop(s2);
        }
        else
            push(s, pop(s2));
    }

    if (valid)
    {
        cout << "The Expression is Valid" << endl;
    }
    else
    {

        cout << "The Expression is not Valid" << endl;
    }
    cout << "The Expression is : ";
    for (int i = 0; i <= s.top; i++)
    {
        cout << s.arr[i];
    }

    return 0;
}