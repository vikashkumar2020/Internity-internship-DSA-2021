// 2. Find given element in sorted array.

#include<bits/stdc++.h>
using namespace std;


int search_key(int arr[],int n,int key)
{
    int l = 0;
    int h = n-1;
    
   
    
    while(l<=h)
    {
    	int mid = l + (h-l)/2;
    	 
    	if(arr[mid]==key)
    	return mid;
    	if(arr[mid]>key)
    	h=mid-1;
    	else
    	l=mid+1;
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