
// ====================== Simple Linear Queue ============================
#include <iostream>
using namespace std;

const int q_size = 10;

struct Queue
{
    int arr[q_size];
    int rear;
    int front;
};

bool isempty(Queue &q)
{
    if (q.front == q.rear)
    {

        return true;
    }
    return false;
}

bool isfull(Queue &q)
{
    if (q.rear == q_size - 1)
    {
        return true;
    }

    return false;
}

void insert(Queue &q, int n)
{
    if (!isfull(q))
    {
        q.arr[++q.rear] = n;
    }
    else
    {
        cout << "Queue is Full" << endl;
    }
}

int Delete(Queue &q)
{
    if (!isempty(q))
    {
        return q.arr[++q.front];
    }
    else
    {
        cout << "Queue is Empty" << endl;
        return -1;
    }
}

void display(Queue &q)
{
    if (isempty(q))
    {
        cout << "Queue is Empty" << endl;
        return;
    }

    for (int i = q.front + 1; i <= q.rear; i++)
    {
        cout << q.arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "==================== This Program is Designed By Hamzuu ====================" << endl;
    Queue q;
    q.rear = -1;
    q.front = -1;

    insert(q, 10);
    insert(q, 11);
    insert(q, 12);
    insert(q, 13);
    insert(q, 14);

    display(q);
    cout << "Deleted: " << Delete(q) << endl;
    cout << "Deleted: " << Delete(q) << endl;
    display(q);
    cout << "==================== @Copyright by hamzuu ===================";
    return 0;
}
