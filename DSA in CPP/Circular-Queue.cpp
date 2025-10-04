// ====================== Circular Queue ============================

#include <iostream>
using namespace std;

const int q_size = 10;
struct Queue
{
    int arr[q_size];
    int front;
    int rear;
};

bool isempty(Queue &q)
{
    return (q.front == -1);
}
bool isfull(Queue &q)
{
    return ((q.front == 0 && q.rear == q_size - 1) || (q.rear + 1 == q.front));
}
void insert(Queue &q, int n)
{
    if (isfull(q))
    {
        cout << "Queue is Full" << endl;
        return;
    }
    else if (q.front == -1)
    {
        q.front = 0;
        q.rear = 0;
    }
    else if (q.front != 0 && q.rear == q_size - 1)
    {
        q.rear = 0;
    }
    else
    {
        q.rear++;
    }
    q.arr[q.rear] = n;
}
int remove(Queue &q)
{
    if (isempty(q))
    {
        cout << "Queue is Empty" << endl;
        return -1;
    }
    int value = q.arr[q.front];
    if (q.front == q.rear)
    {
        q.rear = -1;
        q.front = -1;
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

void display(Queue &q)
{
    if (q.rear >= q.front)
    {
        for (int i = q.front; i <= q.rear; i++)
        {
            cout << q.arr[i] << " ";
        }
    }
    else
    {

        for (int i = 0; i <= q.rear; i++)
        {
            cout << q.arr[i] << " ";
        }
        for (int i = q.front; i < q_size; i++)
        {
            cout << q.arr[i] << " ";
        }
    }
    cout << endl;
}
int main()
{
    Queue q;
    q.front = -1;
    q.rear = -1;
    insert(q, 50);
    insert(q, 90);
    insert(q, 80);
    insert(q, 60);
    insert(q, 40);
    insert(q, 20);
    insert(q, 20);
    insert(q, 20);
    insert(q, 20);
    insert(q, 100);
    display(q);
    cout << "Deleted : " << remove(q) << endl;
    display(q);
    insert(q, 990);
    display(q);
        cout << "\033[33m==================== @Copyright by hamzuu ====================\033[0m" << endl;
    return 0;
}