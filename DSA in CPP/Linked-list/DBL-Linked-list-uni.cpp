
// THis is a full Program of Double-ended Linkedlist-queue According to Sir saqib 
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class DBL_Linkedlist_queue
{
    Node *front;
    Node *rear;

public:
    DBL_Linkedlist_queue()
    {
        front = nullptr;
        rear = nullptr;
    }
    void insert_back(int n)
    {
        Node *newnode = new Node;
        newnode->data = n;
        newnode->next = nullptr;
        if (rear == nullptr)
        {
            front = newnode;
        }
        else
        {
            rear->next = newnode;
        }
        rear = newnode;
    }
    void insert_front(int n)
    {
        if (rear == nullptr)
        {
            cout << "Cannot push from front bcz Queue is empty" << endl;
            return;
        }

        Node *newnode = new Node;
        newnode->data = n;
        newnode->next = front;
        front = newnode;
    }
    int remove_front()
    {
        if (rear == nullptr)
        {
            cout << "queue is empty" << endl;
        }
        else
        {
            int temp = front->data;
            Node *del = front;

            if (front->next == nullptr)
            {
                rear = nullptr;
            }
            else
            {

                front = front->next;
                delete del;
                return temp;
            }
        }
        return -1;
    }
    int remove_rear()
    {
        if (rear == nullptr)
        {
            cout << "queue is empty" << endl;
            return -1;
        }
        int temp = rear->data;
        if (front == rear)
        {
            delete rear;
            front = nullptr;
            rear = nullptr;
            return temp;
        }
        Node *current = front;
        while (current->next != rear)
        {
            current = current->next;
        }
        delete rear;
        rear = current;
        rear->next = nullptr;
        return temp;
    }
    void display()
    {
        if (rear == nullptr)
        {
            cout << "Queuelist is empty" << endl;
        }
        else
        {
            Node *temp = front;
            while (temp != nullptr)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
        cout<<endl;
    }
    
};
int main()
{

    DBL_Linkedlist_queue q;
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
                q.insert_back(y);
                break;
            case 2:
                cout << "1.Remove From front" << endl;
                cout << "2.Remove From Rear" << endl;
                cout << "3.Exit" << endl;

                cin >> z;
                switch (z)
                {
                case 1:

                    cout << "Successfully popped from front : " << q.remove_front() << endl;
                    break;
                case 2:

                    cout << "Successfully popped from back : " << q.remove_rear() << endl;
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

                    q.insert_front(y);
                    break;

                case 2:
                    q.insert_back(y);
                    break;
                default:
                    cout << "Invalid!!" << endl;
                    break;
                }
                break;
            case 2:

                cout << "Successfully popped from front : " << q.remove_front() << endl;
                break;
            case 3:
                exit(0);
            default:
                cout << "Invalid!!" << endl;
                break;
            }
            break;
        case 3:
            q.display();
            break;
        case 4:
            exit(0);
        default:
            break;
        }
    } while (true);

    return 0;
}