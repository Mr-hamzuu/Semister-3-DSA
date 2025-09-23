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

#include <iostream>
using namespace std;

int main()
{
  int arr[9] = {9, 3, 5, 7, 4, 2, 1, 6, 8};
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9-1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  for (int i = 0; i < 9; i++)
  {
    cout<<arr[i]<<" ";
  }
  

  return 0;
}
