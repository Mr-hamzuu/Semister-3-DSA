
// #include <iostream>
// using namespace std;

// void merge(int arr[], int start, int mid, int end)
// {
//     int left_size = mid - start + 1;
//     int right_size = end - mid;
//     int left_arr[left_size];
//     int right_arr[right_size];
//     for (int i = 0; i < left_size; i++)
//     {
//         left_arr[i] = arr[start + i];
//     }
//     for (int i = 0; i < right_size; i++)
//     {
//         right_arr[i] = arr[i + mid + 1];
//     }
//     int i = 0, j = 0, k = start;
//     while (i < left_size && j < right_size)
//     {
//         if (left_arr[i] <= right_arr[j])
//         {
//             arr[k] = left_arr[i];
//             i++;
//         }
//         else
//         {
//             arr[k] = right_arr[j];
//             j++;
//         }
//         k++;
//     }

//     // These two loops are used for remaining elements
//     while (i < left_size)
//     {
//         arr[k] = left_arr[i];
//         i++;
//         k++;
//     }
//     while (j < right_size)
//     {
//         arr[k] = right_arr[j];
//         j++;
//         k++;
//     }
// }
// void Merge_sort(int arr[], int start, int end)
// {
//     if (start < end)
//     {
//         int mid = (start + end) / 2;
//         Merge_sort(arr, start, mid);
//         Merge_sort(arr, mid + 1, end);
//         merge(arr, start, mid, end);
//     }
// }
// int main()
// {
//     int arr[9] = {9, 3, 5, 2, 4, 1, 7, 6, 8};
//     Merge_sort(arr, 0, 8);
//     for (int i = 0; i < 9; i++)
//     {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }

// **********************************LEETCODE QUESTION******************************

//  You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
// Merge nums1 and nums2 into a single array sorted in non-decreasing order.
// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

// Example 1:

// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
// Example 2:

// Input: nums1 = [1], m = 1, nums2 = [], n = 0
// Output: [1]
// Explanation: The arrays we are merging are [1] and [].
// The result of the merge is [1].
// Example 3:

// Input: nums1 = [0], m = 0, nums2 = [1], n = 1
// Output: [1]
// Explanation: The arrays we are merging are [] and [1].
// The result of the merge is [1].
// Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

// Constraints:
// nums1.length == m + n
// nums2.length == n
// 0 <= m, n <= 200
// 1 <= m + n <= 200
// -109 <= nums1[i], nums2[j] <= 109

// Follow up: Can you come up with an algorithm that runs in O(m + n) time?

// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int i=m-1;
//         int j=n-1;
//         int k=m+n-1;
//         while(i>=0&&j>=0){
//             if(nums1[i]<=nums2[j]){
//                 nums1[k]=nums2[j];
//                 j--;
//             }
//             else{
//                 nums1[k]=nums1[i];
//                 i--;
//             }
//             k--;
//         }

//          while(j>=0){
//             nums1[k]=nums2[j];
//             k--;
//             j--;
//         }
//     }
// };







#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end)
{
    int left_size = mid - start + 1;
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
    int i = 0, j = 0, k = start;
    while (i < left_size && j < right_size)
    {
        if (left_arr[i] >= right_arr[j])
        {
            arr[k] = left_arr[i];
            i++;
        }
        else
        {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    // These two loops are used for remaining elements
    while (i < left_size)
    {
        arr[k] = left_arr[i];
        i++;
        k++;
    }
    while (j < right_size)
    {
        arr[k] = right_arr[j];
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
        cout << arr[i] << " ";
    }

    return 0;
}
