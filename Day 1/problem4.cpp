// 4. Find the "Kth" max and min element of an array

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int k;
	cin >> k;
	int arr[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int kth_min = arr[k - 1];
	int kth_max = arr[n - k];

	cout << "kth minimum " << kth_min << "\n";
	cout << "kth maximum " << kth_max << "\n";

	return 0;
}