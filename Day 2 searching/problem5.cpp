// 5. Find given element in sorted array using ternary search

#include<bits/stdc++.h>
using namespace std;

int search_key(int arr[],int n, int key)
{
	int l = 0;
	int h = n - 1;
	while(l<=h)
	{
		int mid1= l + (h-l)/3;
		int mid2= h - (h-l)/3;
		
		if(arr[mid1]==key)
		return mid1;
		if(arr[mid2]==key)
		return mid2;
		
		if(key<arr[mid1])
		h = mid1 - 1;

		else if(key>arr[mid2])
		l = mid2 + 1;
		else{
		l = mid1 + 1;
		h = mid2 - 1;
		}
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