#include <iostream>
using namespace std;

const int q_size = 10;
struct dbl_queue
{
    int arr[q_size];
    int front;
    int rear;
};

bool isempty(dbl_queue &q)
{
    return q.front == -1;
}
bool isfull(dbl_queue &q)
{
    return ((q.front == 0 && q.rear == q_size - 1) || q.rear + 1 == q.front);
}

// Push Functions
void push_rear(dbl_queue &q, int n)
{
    if (isfull(q))
    {
        cout << "Queue is full" << endl;
        return;
    }
    if (isempty(q))
    {
        q.rear = 0;
        q.front = 0;
        q.arr[q.rear] = n;
        return;
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
void push_front(dbl_queue &q, int n)
{
    if (isfull(q))
    {
        cout << "Queue is full" << endl;
        return;
    }
    if (isempty(q))
    {
        q.rear = 0;
        q.front = 0;
        q.arr[q.rear] = n;
        return;
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

// Pop Functions
int pop_front(dbl_queue &q)
{
    if (isempty(q))
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    int data = q.arr[q.front];
    if (q.front == q.rear)
    {
        q.front = -1;
        q.rear = -1;
    }
    else if (q.front == q_size - 1)
    {
        q.front = 0;
    }
    else
    {
        q.front++;
    }
    return data;
}
int pop_rear(dbl_queue &q)
{
    if (isempty(q))
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    int data = q.arr[q.rear];
    if (q.front == q.rear)
    {
        q.front = -1;
        q.rear = -1;
    }
    else if (q.rear == 0)
    {
        q.rear = q_size - 1;
    }
    else
    {
        q.rear--;
    }
    return data;
}

void display(dbl_queue &q)
{
    if (isempty(q))
    {
        cout << "Queue is Empty" << endl;
        return;
    }
    cout << "Double Ended Queue : ";
    int idx = q.front;
    while (true)
    {
        cout << q.arr[idx] << " ";
        if (idx == q.rear)
        {
            break;
        }
        if (idx == q_size - 1)
        {
            idx = 0;
        }
        else
            idx++;
    }
    cout << endl;
}
int main()
{

    dbl_queue q;
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
                push_rear(q, y);
                break;
            case 2:
                cout << "1.Remove From front" << endl;
                cout << "2.Remove From Rear" << endl;
                cout << "3.Exit" << endl;

                cin >> z;
                switch (z)
                {
                case 1:

                    cout << "Successfully popped from front : " << pop_front(q) << endl;
                    break;
                case 2:

                    cout << "Successfully popped from back : " << pop_rear(q) << endl;
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
                    if (isempty(q))
                    {
                        cout << "Cannot push from front bcz Queue is empty" << endl;
                        break;
                    }
                    else
                    {
                        push_front(q, y);
                        break;
                    }
                case 2:
                    push_rear(q, y);
                    break;
                default:
                    cout << "Invalid!!" << endl;
                    break;
                }
                break;
            case 2:

                cout << "Successfully popped from front : " << pop_front(q) << endl;
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