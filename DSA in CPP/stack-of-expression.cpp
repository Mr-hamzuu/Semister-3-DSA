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
    if (s.top < arr_size)
        return false;
    else
        return true;
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
    if (s.top >= 0)
        return false;
    else
        return true;
}
void pop(stack &s)
{
    if (!isempty(s))
        s.top--;
    else
        cout << "Stack is empty";
}
int main()
{
    stack s;
    s.top = -1;
    bool valid=true;
    string exp;
    cout<<"Enter the Expression"<<endl;
    getline(cin,exp);
    for (int i = 0; i < exp.length(); i++)
    {
        char symbol=exp[i];
        if (symbol=='(')
        {
            push(s,symbol);
        }
       if (symbol==')')
        {
            if (isempty(s))
            {
                valid=false;
                break;
            }
            else{
             pop(s);
            }
        }
    }
    if (!isempty(s))
    {
        valid =false;
    }
    
    if (valid)
    {
        cout<<"The Expression is Valid"<<endl;
    }
    else{
        
        cout<<"The Expression is not Valid"<<endl;
    }
    
    
    return 0;
}