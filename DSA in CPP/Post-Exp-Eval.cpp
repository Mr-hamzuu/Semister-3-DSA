// #include<iostream>
// #include<stack>
// using namespace std;

// int main()
// {
//     stack<int> main;
//     stack<int> min;

//     int n[5]={6,3,8,4,2};
//     for (int i = 0; i < 5; i++)
//     {
//         main.push(n[i]);
//        if (min.empty()||n[i]<=min.top())
//        {
//         min.push(n[i]);
//        }

//     }

//     return 0;
// }

// ************************************** Post Exp Evaluation *************************************

#include <iostream>
#include <cmath>

using namespace std;

const int stacksize = 20;
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

int main()
{

    stack s;
    s.top = -1;
    string str = "623+-382/+*2$3+";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            int symbol = str[i] - '0';
            push(s, symbol);
        }
        else
        {
            int op2 = pop(s);
            int op1 = pop(s);
            int ans;
            switch (str[i])
            {
            case '+':

                ans = op1 + op2;
                push(s, ans);
                break;
            case '-':

                ans = op1 - op2;
                push(s, ans);
                break;
            case '*':

                ans = op1 * op2;
                push(s, ans);
                break;
            case '/':

                ans = op1 / op2;
                push(s, ans);
                break;
            case '$':

                ans = pow(op1, op2);
                push(s, ans);
                break;

            default:
                break;
            }
        }
    }
    cout << "Result : " << pop(s) << endl;

    return 0;
}

// ************************************ Question ************************************************

// #include<iostream>
// #include<stack>
// using namespace std;

// int main()
// {
//     stack<int> main;
//     stack<int> min;

//     int n[5]={6,3,8,4,2};
//     for (int i = 0; i < 5; i++)
//     {
//         main.push(n[i]);
//        if (min.empty()||n[i]<=min.top())
//        {
//         min.push(n[i]);
//        }

//     }

//     return 0;
// }

// ************************************ Question ************************************************

// #include <iostream>
// #include <cmath>

// using namespace std;

// const int stacksize = 20;
// struct stack
// {
//     int arr[stacksize];
//     int top;
// };

// int top(stack &s)
// {
//     return s.top;
// }
// bool isfull(stack &s)
// {
//     if (s.top == stacksize - 1)
//     {
//         return true;
//     }
//     return false;
// }
// void push(stack &s, int value)
// {
//     if (isfull(s))
//     {
//         cout << "Stack is full" << endl;
//     }
//     else
//         s.arr[++s.top] = value;
// }
// bool isempty(stack &s)
// {
//     if (s.top != -1)
//     {
//         return false;
//     }
//     return true;
// }
// int pop(stack &s)
// {
//     if (!isempty(s))
//     {
//         return s.arr[s.top--];
//     }
//     return -1;
// }
// void display(stack &s)
// {
//     for (int i = 0; i <= s.top; i++)
//     {
//         cout << s.arr[i] << " ";
//     }
// }
// int main()
// {

//     stack s, s2;
//     s.top = -1;
//     s2.top = -1;

//     for (int i = 0; i < stacksize; i++)
//     {
//         push(s, i + 1);
//     }
//     display(s);
//     cout << endl;
//     int n = 10;
//     for (int i = stacksize; i >= n; i--)
//     {
//         push(s2, pop(s));
//     }
//     pop(s2);
//     while (!isempty(s2))
//     {
//         push(s, pop(s2));
//     }

//     display(s);

//     return 0;
// }