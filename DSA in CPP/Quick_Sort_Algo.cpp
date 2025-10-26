// ********************************* Quicksort Algorithm **********************************
// #include <iostream>
// using namespace std;

// void Swap(int &value1, int &value2)
// {
//   int temp;
//   temp = value1;
//   value1 = value2;
//   value2 = temp;

// }

// int partition(int arr[], int first, int last)
// {
//   int idx = first; //idx is for sorting the less then or equal to element of pivot
//   int pivot = arr[first]; // we assume pivot as array first idx element
//   for (int i = first+1; i <= last; i++)
//   {
//     if (arr[i] <= pivot)
//     {
//       idx++;
//       Swap(arr[i], arr[idx]);
//     }
//   }

//   Swap(arr[first], arr[idx]);
//   return idx;
// }

// void Quicksort(int arr[], int first, int last)
// {
//   if (first < last)
//   {
//     int pivot_idx = partition(arr, first, last); // Return pivot index
//     Quicksort(arr, first, pivot_idx-1); //pass last idx is pivot_index for first half sorting array
//     Quicksort(arr, pivot_idx + 1, last); //now pass first value is pivot idx which is the mid of array
//   }
// }

// int main()
// {
//   int arr[9] = {9, 4, 6, 2, 5, 1, 7, 3, 8};
//   Quicksort(arr, 0, 8);

//   for (int i = 0; i < 9; i++)
//   {
//     cout<<arr[i]<<" ";
//   }
// }

// #include<iostream>
// using namespace std;

// void swap(int &value1,int &value2){
//   int temp=value1;
//   value1=value2;
//   value2=temp;
// }

// int partition(int arr[],int first,int last){
//   int idx=first-1;
//   int pivot=arr[last];
//   for (int i = first; i <last; i++)
//   {
//     if (arr[i]<=pivot)
//     {

//       idx++;
//       swap(arr[idx],arr[i]);

//     }
//   }
//   swap(arr[last],arr[idx+1]);
//   return (idx+1);
// }

// void quicksort(int arr[],int first,int last){
//   if (first<last)
//   {
//     int pivot_idx=partition(arr,first,last);
//     quicksort(arr,first,pivot_idx-1);
//     quicksort(arr,pivot_idx+1,last);
//   }
// }
// int main()
// {
//   int arr[5]={3,2,7,4,1};
//   int n=sizeof(arr)/sizeof(arr[0]);
//   quicksort(arr,0,n-1);
//   for (int i = 0; i < 5; i++)
//   {
//     cout<<arr[i]<<" ";
//   }

//   return 0;
// }

#include <iostream>
using namespace std;

void Swap(int &value1, int &value2)
{
  int temp;
  temp = value1;
  value1 = value2;
  value2 = temp;
}

int partition(int arr[], int first, int last)
{
  int i = first + 1;
  int j = last;
  int pivot = arr[first];
  while (true)
  {
    while (i <= last && arr[i] <= pivot)
    {
      i++;
    }
    while (j >= first && arr[j] > pivot)
    {
      j--;
    }
    if (i >= j)
    {
      break;
    }
    Swap(arr[i], arr[j]);
  }
  Swap(arr[first], arr[j]);
  return j;
}

void Quicksort(int arr[], int first, int last)
{
  if (first < last)
  {
    int pivot_idx = partition(arr, first, last); // Return pivot index
    Quicksort(arr, first, pivot_idx - 1);        // pass last idx is pivot_index for first half sorting array
    Quicksort(arr, pivot_idx + 1, last);         // now pass first value is pivot idx which is the mid of array
  }
}

int main()
{
  int arr[9] = {9, 4, 6, 2, 5, 1, 7, 3, 8};
  Quicksort(arr, 0, 8);

  for (int i = 0; i < 9; i++)
  {
    cout << arr[i] << " ";
  }
}
