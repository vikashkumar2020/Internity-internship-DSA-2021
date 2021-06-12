// 6. Move all the negative elements to one side of the array

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

	// rearrange the array

	int temp = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] < 0)
		{
			if (temp != i)
				swap(arr[i], arr[temp]);
			temp++;
		}
	}

	// output array

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}