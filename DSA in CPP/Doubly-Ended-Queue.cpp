#include <iostream>
using namespace std;

const int q_size = 10;
struct Dbl_Queue
{
    int arr[q_size];
    int front;
    int rear;
};

bool isempty(Dbl_Queue &q)
{
    return (q.front == -1);
}
bool isfull(Dbl_Queue &q)
{
    return ((q.front == 0 && q.rear == q_size - 1) || (q.rear + 1 == q.front));
}

// Front Fucntions
void push_front(Dbl_Queue &q, int n)
{
    if (isfull(q))
    {
        cout << "Queue is full" << endl;
        return;
    }
    if (isempty(q))
    { // first element
        q.front = q.rear = 0;
    }
    if (q.front == 0)
    {
        q.front = q_size - 1;
    }
    else
    {
        q.front--;
    }
    q.arr[q.front] = n;
}
int pop_front(Dbl_Queue &q)
{
    if (isempty(q))
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    int value = q.arr[q.front];
    if (q.front == q.rear)
    {
        q.front = q.rear = -1;
    }
    else if (q.front == q_size - 1)
    {
        q.front = 0;
    }
    else
    {
        q.front++;
    }
    return value;
}

// Rear Functions
void push_back(Dbl_Queue &q, int n)
{
    if (isfull(q))
    {
        cout << "Queue is Full" << endl;
        return;
    }
    if (isempty(q))
    { // first element
        q.front = q.rear = 0;
    }
    if (q.rear == q_size - 1)
    {
        q.rear = 0;
    }
    else
    {
        q.rear++;
    }
    q.arr[q.rear] = n;
}

int pop_back(Dbl_Queue &q)
{
    if (isempty(q))
    {
        cout << "Queue is Empty" << endl;
        return -1;
    }
    int value = q.arr[q.rear];
    if (q.rear == 0)
    {
        q.rear = q_size - 1;
    }
    else if (q.rear == q.front)
    {
        q.rear = q.front = -1;
    }
    else
    {
        q.rear--;
    }
    return value;
}
void display(Dbl_Queue &q)
{
    if (isempty(q))
    {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Queue elements: ";
    int i = q.front;

    for (;;)
    {
        cout << q.arr[i] << " ";
        if (i == q.rear)
            break; // stop at rear

        // move forward circularly
        if (i == q_size - 1)
            i = 0;
        else
            i++;
    }
    cout << endl;
}

int main()
{
    Dbl_Queue q;
    q.front = -1;
    q.rear = -1;
    do
    {
        cout << "1.Input Restricted" << endl;
        cout << "2.Output Restricted" << endl;
        cout << "3.Display" << endl;
        cout << "4.Exit" << endl;
        int x, n, y, z;
        cin >> x;
        switch (x)
        {
        case 1:
            cout << "*************************** Input Restricted *************************" << endl;
            cout << "1.Insertion" << endl;
            cout << "2.Removal" << endl;
            cout << "3.Exit" << endl;

            cin >> n;
            switch (n)
            {
            case 1:

                cout << "Enter the value you want to enter";
                cin >> y;
                push_back(q, y);
                break;
            case 2:
                cout << "1.Remove From front" << endl;
                cout << "2.Remove From Rear" << endl;
                cout << "3.Exit" << endl;

                cin >> z;
                switch (z)
                {
                case 1:
                   
                    cout << "Successfully popped from front : " <<pop_front(q)<< endl;
                    break;
                case 2:
                   
                    cout << "Successfully popped from back : " << pop_back(q)<< endl;
                    break;
                case 3:
                    exit(0);
                default:
                    cout << "Invalid!!" << endl;
                    break;
                }
                break;
            }
            break;
        case 2:
            cout << "*************************** Output Restricted *************************" << endl;
            cout << "1.Insertion" << endl;
            cout << "2.Removal" << endl;
            cout << "3.Exit" << endl;
            cin >> n;
            switch (n)
            {
            case 1:
                cout << "Enter the value you want to enter";
                cin >> y;
                cout << "1.Insert From front" << endl;
                cout << "2.Insert From Rear" << endl;

                cin >> z;
                switch (z)
                {
                case 1:
                    push_front(q, y);
                    break;
                case 2:
                    push_back(q, y);
                    break;
                default:
                    cout << "Invalid!!" << endl;
                    break;
                }
                break;
            case 2:
              
                cout << "Successfully popped from front : "<<  pop_front(q) << endl;
                break;
            case 3:
                exit(0);
            default:
                cout << "Invalid!!" << endl;
                break;
            }
            break;
        case 3:
            display(q);
            break;
        case 4:
            exit(0);
        default:
            break;
        }
    } while (true);

    return 0;
}