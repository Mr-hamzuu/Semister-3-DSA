
// // **********************infix to prefix**********************

// #include <iostream>
// using namespace std;
// const int s_size = 10;
// struct stack
// {
//     char arr[s_size];
//     int top;
// };
// bool isfull(stack &s)
// {
//     if (s.top == s_size - 1)
//     {
//         return true;
//     }
//     return false;
// }
// void push(stack &s, char n)
// {
//     if (!isfull(s))
//     {
//         s.arr[++s.top] = n;
//         return;
//     }
//     cout << "Stack is full" << endl;
//     return;
// }
// bool isempty(stack &s)
// {
//     if (s.top == -1)
//     {
//         return true;
//     }
//     return false;
// }
// char pop(stack &s)
// {
//     if (!isempty(s))
//     {
//         return s.arr[s.top--];
//     }
//     cout << "stack is empty" << endl;
//     return -1;
// }
// char stacktop(stack &s)
// {
//     return s.arr[s.top];
// }
// int precedence(char s)
// {
//     if (s == '+' || s == '-')
//     {
//         return 1;
//     }
//     else if (s == '*' || s == '/')
//     {
//         return 2;
//     }
//     else if (s == '$')
//     {
//         return 3;
//     }
//     return 0;
// }
// int main()
// {
//     stack s;
//     stack exp;
//     s.top = -1;
//     exp.top = -1;
//     string str = "(k*j+(l-m)$t)";
//     string str2;
//     for (int i = str.length() - 1; i >= 0; i--)
//     {
//         str2 += str[i];
//     }
//     for (int i = 0; i < str2.length(); i++)
//     {
//         if (str2[i] == '(')
//         {
//             str2[i] = ')';
//         }
//         else if (str2[i] == ')')
//         {
//             str2[i] = '(';
//         }
//     }
//     char symbol;
//     for (int i = 0; i < str2.length(); i++)
//     {
//         symbol = str2[i];
//         if (symbol == '(')
//         {
//             push(exp, symbol);
//         }
//         else
//         {
//             if ((symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z'))
//             {
//                 push(s, symbol);
//             }
//             else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '$')
//             {
//                 while (!isempty(exp) && precedence(stacktop(exp)) >= precedence(symbol))
//                 {
//                     push(s, pop(exp));
//                 }
//                 push(exp, symbol);
//             }
//             else if (symbol == ')')
//             {
//                 while (!isempty(exp) && stacktop(exp) != '(')
//                 {
//                     push(s, pop(exp));
//                 }
//                 pop(exp);
//             }
//         }
//     }
//     while (!isempty(exp))
//     {
//         if (stacktop(exp) == '(')
//         {
//             pop(exp);
//         }
//         else
//         {
//             push(s, pop(exp));
//         }
//     }

//     for (int i = s.top; i >= 0; i--)
//     {
//         cout << s.arr[i];
//     }

//     return 0;
// }

// ************************************ Linear Queue ******************************************

// #include <iostream>
// using namespace std;
// const int q_size = 10;
// struct queue
// {
//     string arr[q_size];
//     int front;
//     int back;
// };
// bool isfull(queue &q)
// {
//     return (q.back == q_size-1);
// }
// bool isemty(queue &q)
// {
//     return q.front > q.back;
// }
// void push(queue &q, string n)
// {
//     if (!isfull(q))
//     {
//         q.arr[++q.back] = n;
//         return;
//     }
//     cout << "Queue is Full" << endl;
//     return;
// }
// void pop(queue &q)
// {
//     if (!isemty(q))
//     {
//         q.front++;
//         return;
//     }
//     cout << "Queue is Empty" << endl;
//     return;
// }
// void display(queue &q)
// {
//     if (isemty(q))
//     {
//         cout<<"Queue is empty"<<endl;
//         return;
//     }

//     for (int i = q.front; i <= q.back; i++)
//     {
//         cout << q.arr[i] << " ";
//     }
//     cout << endl;
// }
// int main()
// {
//     queue q;
//     q.front = 0;
//     q.back = -1;
//     push(q, "Hamza");
//     push(q, "Umer");
//     push(q, "Ali");

//     display(q);
//     pop(q);
//     pop(q);

//     display(q);
//     return 0;
// }

// ************************************** circular queue ***********************************

// #include <iostream>
// using namespace std;
// const int q_size = 10;
// struct circular
// {
//     int arr[q_size];
//     int front;
//     int rear;
// };
// bool isfull(circular &c)
// {
//     return ((c.front == 0 && c.rear == q_size - 1) && c.rear + 1 == c.front);
// }
// bool isempty(circular &c)
// {
//     return c.front == -1;
// }
// void push_front(circular &c, int n)
// {
//     if (isfull(c))
//     {
//         cout << "Queue is full" << endl;
//         return;
//     }
//     else if (c.front == -1)
//     {
//         c.front = c.rear = 0;
//     }

//     else if (c.front == 0 && c.rear != q_size - 1)
//     {
//         c.front = q_size - 1;
//     }
//     else
//     {
//         c.front--;
//     }
//     c.arr[c.front] = n;
//     return;
// }
// void push_back(circular &c, int n)
// {
//     if (isfull(c))
//     {
//         cout << "Queue is full" << endl;
//         return;
//     }
//     if (c.rear == -1)
//     {
//         c.front = c.rear = 0;
//         c.arr[c.rear] = n;
//         return;
//     }
//     else if (c.rear == q_size - 1 && c.front != 0)
//     {
//         c.rear = 0;
//     }
//     else
//     {
//         c.rear++;
//     }

//     c.arr[c.rear] = n;
//     return;
// }
// int pop_front(circular &c)
// {
//     if (isempty(c))
//     {
//         cout << "Queue is empty" << endl;
//         return -1;
//     }
//     int value = c.arr[c.front];
//     if (c.front == c.rear)
//     {
//         c.front = -1;
//         c.rear = -1;
//         return -1;
//     }
//     if (c.front == q_size - 1)
//     {
//         c.front = 0;
//     }
//     else
//     {
//         c.front++;
//     }
//     return value;
// }
// void display(circular &c){
//     if (isempty(c))
//     {
//         cout<<"Queue is empty"<<endl;
//         return;
//     }
//     int i=c.front;
//     while (true)
//     {
//         cout<<c.arr[i]<<" ";
//         if (i==q_size-1)
//         {
//             i=0;
//         }
//         if (i==c.rear)
//         {
//             break;
//         }
//         i++;
//     }

//     cout<<endl;

// }
// int main()
// {
//  circular c;
//  c.front=-1;
//  c.rear=-1;
//  push_back(c,45);
//  push_back(c,45);
//  push_back(c,45);
//  push_back(c,45);
//  push_back(c,45);
//  display(c);

//  pop_front(c);
//  display(c);
//     return 0;
// }

// // ************************** Double ended queue with linear queue ******************

// #include <iostream>
// using namespace std;
// const int q_size = 10;
// struct queue
// {
//     int arr[q_size];
//     int front;
//     int back;
// };
// bool isfull(queue &q)
// {
//     return (q.back == q_size - 1);
// }
// bool isemty(queue &q)
// {
//     return q.front >q.back;
// }
// void push_back(queue &q, int n)
// {
//     if (!isfull(q))
//     {
//         q.arr[++q.back] = n;
//         return;
//     }
//     cout << "Queue is Full" << endl;
//     return;
// }
// int pop_back(queue &q)
// {
//     if (!isemty(q))
//     {
//         return q.arr[q.back--];
//     }
//     cout << "Queue is Empty" << endl;
//     return -1;
// }
// void push_front(queue &q, int n)
// {
//     if (q.front>0)
//     {
//         q.arr[--q.front] = n;
//         return;
//     }
//     cout << "No space at front" << endl;
//     return;
// }
// void pop_front(queue &q)
// {
//     if (!isemty(q))
//     {
//         q.front++;
//         return;
//     }
//     cout << "Queue is Empty" << endl;
//     return;
// }
// void display(queue &q)
// {
//     if (isemty(q))
//     {
//         cout << "Queue is empty" << endl;
//         return;
//     }

//     for (int i = q.front; i <= q.back; i++)
//     {
//         cout << q.arr[i] << " ";
//     }
//     cout << endl;
// }

// void merge(int arr[],int start,int mid,int end){
//     int left_size=mid-start+1;
//     int right_size=end-mid;
//     int left[left_size];
//     int right[right_size];

//     for (int i = 0; i < left_size; i++)
//     {
//         left[i]=arr[start+i];
//     }
//     for (int i = 0; i < right_size; i++)
//     {
//         right[i]=arr[mid+1+i];
//     }

//     int i=0,j=0,k=start;
//     while (i<left_size&&j<right_size)
//     {
//         if (left[i]<=right[j])
//         {
//             arr[k]=left[i];
//             i++;
//         }
//         else{
//             arr[k]=right[j];
//             j++;
//         }
//         k++;
//     }

//     while (i<left_size)
//     {
//         arr[k]=left[i];
//         i++;
//         k++;
//     }
//     while (j<right_size)
//     {
//         arr[k]=right[j];
//         j++;
//         k++;
//     }

// }
// void mergesort(int arr[],int start,int end){
//     if (start<end)
//     {
//         int mid=(start+end)/2;
//         mergesort(arr,start,mid);
//         mergesort(arr,mid+1,end);
//         merge(arr,start,mid,end);
//     }

// }

// int main()
// {
// queue q;
// q.front=0;
// q.back=-1;
// push_back(q,75);
// push_back(q,34);
// push_back(q,85);
// push_back(q,45);
// push_back(q,25);
// display(q);
// int temp[q_size];
// int count=0;
// while (!isemty(q))
// {
//     temp[count++]=pop_back(q);
// }
// mergesort(temp,0,count-1);

// for (int i = 0; i < count; i++)
// {
//     push_back(q,temp[i]);
// }

// display(q);
//     return 0;
// }

// #include<iostream>
// using namespace std;
// const int q_size=10;
// struct queue
// {
//     int arr[q_size];
//     int front;
//     int rear;
//     int count;
// };

// bool isempty(queue &q){
//     return (q.count==0);
// }
// bool isfull(queue &q){
//     return (q.count==q_size-1);
// }
// void push(queue &q,int n){
//     if (isfull(q))
//     {
//         cout<<"Queue is Full"<<endl;
//         return;
//     }
//     if (q.rear==q_size-1&&q.front!=0)
//     {
//         q.rear=0;
//     }
//    q.arr[++q.rear]=n;
//    q.count++;
// }
// int pop(queue &q){
//     if (isempty(q))
//     {
//         cout<<"Queue is empty"<<endl;
//         return -1;
//     }
//     if (q.front==q_size-1)
//     {
//         q.front=0;
//     }
//     --q.count;
//     return q.arr[q.front++];
// }
// void display(queue &q){
//     if (isempty(q))
//     {
//         cout<<"Queue is Empty"<<endl;
//         return;
//     }
//     else{

//         int i=q.front;
//         while (true)
//         {
//             cout<<q.arr[i]<<" ";
//             if (i==q_size-1)
//             {
//                 i=0;
//             }
//             if (i==q.rear)
//             {
//                 break;
//             }
//             i++;
//         }

//     }
//     cout<<endl;
// }
// int main()
// {
//     queue q;
//     q.front=0;
//     q.rear=-1;
//     q.count=0;
//     push(q,34);
//     push(q,46);
//     push(q,74);
//     push(q,84);
//     push(q,84);
//     push(q,84);
//     push(q,84);
//     push(q,84);
//     push(q,84);
//     push(q,84);
//     push(q,84);
//     display(q);
//     pop(q);
//     pop(q);
//     pop(q);

//     display(q);
//     return 0;
// }





// ********************************** vehicle and parking stack and queue ********************************
// #include <iostream>
// using namespace std;

// const int stack_size = 5;
// const int q_size = 10;
// struct stack
// {
//     string cars[stack_size];
//     int top;
// };
// bool s_isempty(stack &s)
// {
//     return (s.top == -1);
// }
// bool s_isfull(stack &s)
// {
//     return (s.top == stack_size - 1);
// }
// void insert(stack &s, string n)
// {
//     if (s_isfull(s))
//     {
//         cout << "Parking is full" << endl;
//         return;
//     }
//     s.cars[++s.top] = n;
//     return;
// }
// string remove(stack &s)
// {
//     if (s_isempty(s))
//     {
//         cout << "Parking is Empty" << endl;
//         return "";
//     }
//     return s.cars[s.top--];
// }

// // Queue
// struct queue
// {
//     string arr[q_size];
//     int front;
//     int rear;
// };
// bool q_isempty(queue &q)
// {
//     return q.rear == -1;
// }
// bool q_isfull(queue &q)
// {
//     return ((q.front == -1 && q.rear == q_size - 1) || q.rear + 1 == q.front);
// }
// void push_back(queue &q, string n)
// {
//     if (q_isfull(q))
//     {
//         cout << "waiting line is full" << endl;
//         return;
//     }
//     if (q_isempty(q))
//     {
//         q.front = 0;
//         q.rear = 0;
//     }

//     else if (q.front != 0 && q.rear == q_size - 1)
//     {
//         q.rear = 0;
//     }
//     else
//     {
//         q.rear++;
//     }
//     q.arr[q.rear] = n;
// }
// string pop_front(queue &q)
// {
//     if (q_isempty(q))
//     {
//         cout << "waiting line is empty" << endl;
//         return "";
//     }
//     string value = q.arr[q.front];
//     if (q.front == q.rear)
//     {
//         q.front = q.rear = -1;
//     }
//     else if (q.front == q_size - 1)
//     {
//         q.front = 0;
//     }
//     else
//     {
//         q.front++;
//     }
//     return value;
// }

// void display(queue &q, stack &s)
// {
//     if (s_isempty(s))
//     {
//         cout << "parking is empty" << endl;
//     }
//     else
//     {
//         for (int i = 0; i <= s.top; i++)
//         {
//             cout << s.cars[i] << endl;
//         }
//     }
//     if (q_isempty(q))
//     {

//         cout << "line is empty" << endl;
//     }
//     else
//     {
//         int i = q.front;
//         while (true)
//         {
//             cout << q.arr[i] << " ";
//             if (i == q_size - 1)
//             {
//                 i = 0;
//             }
//             if (i == q.rear)
//             {
//                 break;
//             }
//             i++;
//         }
//     }
// }
// int main()
// {
//     queue q;
//     q.front = -1;
//     q.rear = -1;
//     stack s;
//     s.top = -1;
//     int choice;
//     string vehicle;
//     while (true)
//     {
//         cout << "1.Park a vehicle\n2.Remove a Vehicle\n3.Display Status\n4.Exit" << endl;
//         cin >> choice;
//         switch (choice)
//         {
//         case 1:

//             cout << "Enter a name of vehicle : ";
//             cin.ignore();
//             getline(cin, vehicle);
//             if (!s_isfull(s))
//             {
//                 insert(s, vehicle);
//                 cout << vehicle << " is successfully parked" << endl;
//             }
//             else
//             {
//                 push_back(q, vehicle);
//                 cout << vehicle << " is waiting in line" << endl;
//             }

//             break;
//         case 2:
//             vehicle = remove(s);
//             if (vehicle != "")
//             {
//                 cout << vehicle << " has left the parking" << endl;
//             }
//             if (!q_isempty(q))
//             {
//                 string nextvehicle = pop_front(q);
//                 insert(s, nextvehicle);
//                 cout << nextvehicle << " moved from waiting" << endl;
//             }

//             break;
//         case 3:
//             display(q, s);
//             break;
//         case 4:
//             exit(0);
//         default:
//             break;
//         }
//     }

//     return 0;
// }



