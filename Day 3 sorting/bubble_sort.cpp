// 1. Implementation of bubble sort

#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        bool flag = false;

        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j+1]<arr[j])
            swap(arr[j],arr[j+1]);
            flag = true;
        }
        if(flag==false)
        return;
    }
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

    bubble_sort(arr,n);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}