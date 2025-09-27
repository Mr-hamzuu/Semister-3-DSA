#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end)
{
    int left_size = mid - start+1;
    int right_size = end - mid;
    int left_arr[left_size];
    int right_arr[right_size];
    for (int i = 0; i < left_size; i++)
    {
        left_arr[i] = arr[start + i];
    }
    for (int i = 0; i < right_size; i++)
    {
        right_arr[i] = arr[i + mid + 1];
    }
    int i=0,j=0,k=start;
    while (i<left_size&&j<right_size)
    {
        if (left_arr[i]<=right_arr[j])
        {
            arr[k]=left_arr[i];
            i++;
        }
        else{
            arr[k]=right_arr[j];
            j++;
        }
        k++;
    }

    //These two loops are used for remaining elements
    while (i<left_size)
    {
        arr[k]=left_arr[i];
        i++;
        k++;
    }
    while (j<right_size)
    {
        arr[k]=right_arr[j];
        j++;
        k++;
    }
    
}
void Merge_sort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        Merge_sort(arr, start, mid);
        Merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}
int main()
{
    int arr[9] = {9, 3, 5, 2, 4, 1, 7, 6, 8};
    Merge_sort(arr, 0, 8);
    for (int i = 0; i < 9; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}