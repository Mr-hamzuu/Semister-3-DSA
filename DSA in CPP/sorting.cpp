#include<iostream>
using namespace std;

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