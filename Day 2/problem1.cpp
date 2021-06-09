// Find given element in given array (might be unsorted)

#include<bits/stdc++.h>
using namespace std;


int search_key(int arr[],int n,int key)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        return i;
    }
    return INT_MAX;
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

    int key;
    cin>>key;

    if(search_key(arr,n,key)!=INT_MAX)
    cout<<"element found at index "<<search_key(arr,n,key);
    else
    cout<<"element not found";

    return 0;
}