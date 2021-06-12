// 2.Reverse the array

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int arr[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	// reverse part

	for (int i = 0; i < n / 2; i++)
	{
		swap(arr[i], arr[n - i - 1]);
	}

	// output array

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}