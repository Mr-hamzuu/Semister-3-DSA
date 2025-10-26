#include<iostream>
using namespace std;

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionsort(int arr[],int size){
    for (int i = 0; i < size-1; i++)
    {
        int minvalue=i;
        for (int j = i+1; j < size; j++)
        {
            if (arr[j]<arr[minvalue])
            {
                minvalue=j;
            } 
        }
        int temp=arr[i];
        arr[i]=arr[minvalue];
        arr[minvalue]=temp;        
    }
    
}
int main()
{
    int arr[]={34,545,7,67,8,4};
    for (int i = 0; i < 6; i++)
    {
        for (int j = i+1; j < 6; j++)
        {
            if (arr[i]>arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
            
        }
        
    }
    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<endl;
    }
    
    
    return 0;
}