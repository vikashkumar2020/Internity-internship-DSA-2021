// implementation of radix sort

#include <bits/stdc++.h>
using namespace std;

void countSort(int arr[], int n, int p)
{
	int ans[n]; 
	int i, count[10] = { 0 };

	for (i = 0; i < n; i++)
		count[(arr[i] / p) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--) {
		ans[count[(arr[i] / p) % 10] - 1] = arr[i];
		count[(arr[i] / p) % 10]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = ans[i];
}

void rSort(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];

	for (int p = 1; mx / p > 0; p *= 10)
		countSort(arr, n, p);
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

	rSort(arr, n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}
