
// ====================== Simple Linear Queue ============================
// #include <iostream>
// using namespace std;

// const int q_size = 10;

// struct Queue
// {
//     int arr[q_size];
//     int rear;
//     int front;
// };

// bool isempty(Queue &q)
// {
//     if (q.front == q.rear)
//     {
        
//         return true;
//     }
//     return false;

// }

// bool isfull(Queue &q)
// {
//     if (q.rear == q_size - 1)
//     {
//         return true;
//     }
    
//     return false;
// }

// void insert(Queue &q, int n)
// {
//     if (!isfull(q))
//     {
//         q.arr[++q.rear] = n;
//     }
//     else
//     {
//         cout << "Queue is Full" << endl;
//     }
// }

// int Delete(Queue &q)
// {
//     if (!isempty(q))
//     {
//         return q.arr[++q.front];
//     }
//     else
//     {
    //         cout << "Queue is Empty" << endl;
    //         return -1;  
    //     }
    // }
    
    // void display(Queue &q)
    // {
        //     if (isempty(q))
        //     {
//         cout << "Queue is Empty" << endl;
//         return;
//     }

//     for (int i = q.front + 1; i <= q.rear; i++)
//     {
    //         cout << q.arr[i] << " ";
//     }
//     cout << endl;
// }

// int main()
// {
    //     cout<<"==================== This Program is Designed By Hamzuu ===================="<<endl;
    //     Queue q;
    //     q.rear = -1;
    //     q.front = -1; 

//     insert(q, 10);
//     insert(q, 11);
//     insert(q, 12);
//     insert(q, 13);
//     insert(q, 14);

//     display(q);
//     cout << "Deleted: " << Delete(q) << endl; 
//     cout << "Deleted: " << Delete(q) << endl; 
//     display(q); 
//     cout<<"==================== @Copyright by hamzuu ===================";
//     return 0;
// }



// ====================== Circular Queue ============================
#include <iostream>
using namespace std;

const int q_size = 10;

struct Queue {
    int arr[q_size];
    int rear;
    int front;
};

bool isempty(Queue &q) {
    return (q.front == -1);
}

// check if full
bool isfull(Queue &q) {
    return ((q.front == 0 && q.rear == q_size - 1) || (q.rear + 1 == q.front));
}

// insert element
void insert(Queue &q, int n) {
    if (isfull(q)) {
        cout << "Queue is Full!" << endl;
        return;
    }
    if (q.front == -1) { // first element
        q.front = q.rear = 0;
    }
    else if (q.rear == q_size - 1 && q.front != 0) {
        q.rear = 0; // wrap around
    }
    else {
        q.rear++;
    }
    q.arr[q.rear] = n;
}

// delete element
int Delete(Queue &q) {
    if (isempty(q)) {
        cout << "Queue is Empty" << endl;
        return -1;
    }

    int data = q.arr[q.front];

    if (q.front == q.rear) { // only one element
        q.front = q.rear = -1;
    }
    else if (q.front == q_size - 1) {
        q.front = 0; // wrap around
    }
    else {
        q.front++;
    }
    return data;
}

// display queue
void display(Queue &q) {
    if (isempty(q)) {
        cout << "Queue is Empty" << endl;
        return;
    }

    cout << "Queue elements: ";
    if (q.rear >= q.front) {
        for (int i = q.front; i <= q.rear; i++)
            cout << q.arr[i] << " ";
    }
    else {
        for (int i = q.front; i < q_size; i++)
            cout << q.arr[i] << " ";
        for (int i = 0; i <= q.rear; i++)
            cout << q.arr[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "==================== This Program is Designed By Hamzuu ====================" << endl;

    Queue q;
    q.rear = q.front = -1;

    insert(q, 10);
    insert(q, 11);
    insert(q, 12);
    insert(q, 13);
    insert(q, 14);
    insert(q, 15);
    insert(q, 16);
    insert(q, 17);
    insert(q, 18);
    insert(q, 19);

    display(q);

    cout << "Deleted: " << Delete(q) << endl;
    cout << "Deleted: " << Delete(q) << endl;

    display(q);

    insert(q, 99);
    insert(q, 100);

    display(q);

    cout << "==================== @Copyright by hamzuu ====================" << endl;
    return 0;
}
