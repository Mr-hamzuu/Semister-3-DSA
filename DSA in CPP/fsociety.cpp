// for finding single no in array
// #include<iostream>
// using namespace std;

// int main()
// {
//     int arr[5]={4,3,2,4,3};
//     int ans=0;
//     for (int i = 0; i < 5; i++)
//     {
//         ans=ans^arr[i];
//     }
//   cout<<ans;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//   int arr[9] = {9, 3, 5, 7, 4, 2, 1, 6, 8};
// bubble sort
// for (int i = 0; i < 9; i++)
// {
//   for (int j = 0; j < 9-1; j++)
//   {
//     if (arr[j] > arr[j + 1])
//     {
//       int temp = arr[j];
//       arr[j] = arr[j + 1];
//       arr[j + 1] = temp;
//     }
//   }
// }

// selection sort
//   for (int i = 0; i < 9; i++)
//   {
//     int minno = i;
//     for (int j = i + 1; j < 9; j++)
//     {
//       if (arr[minno] > arr[j])
//       {
//         minno = j;
//       }
//     }
//     if (minno != i)
//     {
//       int temp = arr[i];
//       arr[i] = arr[minno];
//       arr[minno] = temp;
//     }
//   }
//   for (int i = 0; i < 9; i++)
//   {
//     cout << arr[i] << " ";
//   }

//   return 0;
// }


// #include <iostream>
// using namespace std;

// int main()
// {
//   int arr[9] = {9, 4, 6, 2, 5, 1, 7, 3, 8};
//   int up = 0;
//   int down = 8;
//   int first = 0, last = 8;
//   int pivot = arr[first];

//   for (int i = 0; i < 9; i++)
//   {
//     cout << arr[i] << " ";
//   }
//   cout << endl;
//   while (up < down)
//   {
//     if (arr[up] > pivot || arr[down] <= pivot)
//     {
//       int temp = arr[up];
//       arr[up] = arr[down];
//       arr[down] = temp;
//       up++;
//       down--;
//     }

//     pivot = arr[first];

//   }
//   for (int i = 0; i < 9; i++)
//   {
//     cout << arr[i] << " ";
//   }

//   return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//   int arr[9] = {9, 4, 6, 2, 5, 1, 7, 3, 8};
//   int stack[50];
//   int top = -1;

//   stack[++top] = 0;
//   stack[++top] = 8; //{0,8}

//   cout << "Unsorted : ";
//   for (int i = 0; i < 9; i++)
//   {
//     cout << arr[i] << " ";
//   }
//   cout << endl;

//   while (top >= 0)
//   {

//     int last = stack[top--];
//     int first = stack[top--];
//     int pivot = arr[first];
//     int up = first;
//     int down = last;
//     while (up < down)
//     {

//       while (arr[down] > pivot && up < down)
//       {
//         down--;
//       }
//       while (arr[up] <= pivot && up < down)
//       {
//         up++;
//       }

//       if (up < down)
//       {
//         int temp = arr[up];
//         arr[up] = arr[down];
//         arr[down] = temp;
//       }
//     }

//     arr[first] = arr[up];
//     arr[up] = pivot;

//     int pivotidx = up;
//     if (first < pivotidx - 1)
//     {
//       stack[++top] = first;
//       stack[++top] = pivotidx - 1;
//     }
//     if (pivotidx + 1 < last)
//     {
//       stack[++top] = pivotidx + 1;
//       stack[++top] = last;
//     }
//   }

//   cout << "Sorted : ";
//   for (int i = 0; i < 9; i++)
//   {
//     cout << arr[i] << " ";
//   }

//   return 0;
// }
