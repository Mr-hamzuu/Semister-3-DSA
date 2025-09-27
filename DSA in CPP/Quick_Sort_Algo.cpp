// ********************************* Quicksort Algorithm **********************************
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
  int idx = first; //idx is for sorting the less then or equal to element of pivot
  int pivot = arr[first]; // we assume pivot as array first idx element 
  for (int i = first+1; i < last; i++)
  {
    if (arr[i] <= pivot)
    {
      idx++;
      Swap(arr[i], arr[idx]);
    }
  }

  Swap(arr[first], arr[idx]);
  return idx;
}

void Quicksort(int arr[], int first, int last)
{
  if (first < last)
  {
    int pivot_idx = partition(arr, first, last); // Return pivot index
    Quicksort(arr, first, pivot_idx); //pass last idx is pivot_index for first half sorting array
    Quicksort(arr, pivot_idx + 1, last); //now pass first value is pivot idx which is the mid of array
  }
}

int main()
{
  int arr[9] = {9, 4, 6, 2, 5, 1, 7, 3, 8};
  Quicksort(arr, 0, 9);

  for (int i = 0; i < 9; i++)
  {
    cout<<arr[i]<<" ";
  }
}