// 4. Find given element in rotated sorted array.

#include<bits/stdc++.h>
using namespace std;

int rot_search(int arr[],int key,int l, int h)
{
	if(l<=h)
	{
		int mid = l+(h-l)/2;
		
		if (arr[mid]==key)
        return mid;
 
    	if (arr[l] <= arr[mid])
    	{
        	if (key >= arr[l] && key <= arr[mid])
            return rot_search(arr, l, mid - 1, key);
            
			return rot_search(arr, mid + 1, h, key);
    	}
    	if (key >= arr[mid] && key <= arr[h])
        return rot_search(arr, mid + 1, h, key);
 
        return rot_search(arr, l, mid - 1, key);
	}
	return INT_MAX;
}

int search_key(int arr[],int n,int key)
{
	int l = 0;
	int h = n-1;
	
	return rot_search(arr,key,l,h);
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