// 7. Find the Union and Intersection of the two sorted arrays.

#include <bits/stdc++.h>
using namespace std;

void union_of_two(int arr[],int brr[],int n,int m)
{
	int i=0,j=0;
	
	while(i<n && j<m)
	{
		if(arr[i]==brr[j])
		{
			cout<<arr[i]<<" ";
			j++;
			i++;
		}
		if(arr[i]>brr[j])
		cout<<brr[j++]<<" ";
		if(arr[i]<brr[j])
		cout<<arr[i++]<<" ";
	}
	
	while(i<n)
	cout<<arr[i++]<<" ";
	while(j<m)
	cout<<brr[j++]<<" ";
}

void intersection_of_two(int arr[],int brr[],int n,int m)
{
	int i=0,j=0;
	
	while(i<n && j<m)
	{
		if(arr[i]==brr[j])
		{
			cout<<arr[i]<<" ";
			i++;
			j++;
		}
		if(arr[i]>brr[j])
		j++;
		if(arr[i]<brr[j])
		i++;
	}
}
	int main()
	{
	int n;
	cin >> n;

	int arr[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	
	int m;
	cin >> m;

	int brr[m];

	for (int i = 0; i < m; i++)
	{
		cin >> brr[i];
	}
	
	union_of_two(arr,brr,n,m);
	cout<<"\n";
	intersection_of_two(arr,brr,n,m);
	
	return 0;
}