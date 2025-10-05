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
      if (isempty(q)) {   // first element
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
      if (isempty(q)) {   // first element
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
void display(Dbl_Queue &q) {
    if (isempty(q)) {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Queue elements: ";
    int i = q.front;

    for (;;) {
        cout << q.arr[i] << " ";
        if (i == q.rear) break;   // stop at rear

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
    push_front(q, 1);
    push_front(q, 2);
    push_front(q, 3);
    push_front(q, 14);
    push_front(q, 14);
    push_front(q, 14);
    push_front(q, 5);
    push_front(q, 14);
  
    push_back(q, 14);
    display(q);
    pop_front(q);
    display(q);
    push_back(q, 14);
    display(q);
    pop_back(q);
    display(q);
    return 0;
}