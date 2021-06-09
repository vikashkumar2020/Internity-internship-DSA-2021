// 3. Find minimum element in rotated sorted array.
#include<bits/stdc++.h>
using namespace std;

int min_ele(int arr[], int n)
    {
        
        int low = 0;
        int high = n-1;
        
        while(low < high)
        {
            int mid = low + (high - low)/2;
            if (arr[mid] == arr[high])
                high--;
            else if(arr[mid] > arr[high])
                low = mid + 1;
            else
                high = mid;
        }
        return arr[high];
    }

int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    cout<<"minimum element in array "<<min_ele(arr,n);
    
    return 0;
}
