// 3. Find the maximum and minimum element in an array

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

	int minim = INT_MAX, maxim = INT_MIN;

	// min and max

	for (int i = 0; i < n; i++)
	{
		minim = min(minim, arr[i]);

		maxim = max(maxim, arr[i]);
	}

	cout << "minimum in array " << minim << "\n";
	cout << "maximum in array " << maxim << "\n";

	return 0;
}