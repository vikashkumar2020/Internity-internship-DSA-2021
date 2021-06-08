// 8. Given an array of digits check if the array is palindrome or not.

#include <bits/stdc++.h>
using namespace std;

bool check_palin(int arr[],int n)
{
	if(n==0 || n==1)
	return true;
	
	for(int i=0;i<n/2;i++)
	{
		if(arr[i]!=arr[n-i-1])
		return false;
	}
	return true;
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
	
	if(check_palin(arr,n))
	cout<<"palindrome";
	else
	cout<<"Not palindrome";
	
	return 0;
}