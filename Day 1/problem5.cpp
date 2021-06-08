//5. Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo

#include <bits/stdc++.h>
using namespace std;

void sort_fun(int arr[], int n)
{
    int c0 = 0, c1 = 0, c2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            c0++;
        if (arr[i] == 1)
            c1++;
        if (arr[i] == 2)
            c2++;
    }

    for (int i = 0; i < c0; i++)
        arr[i] = 0;

    for (int i = c0; i < (c0 + c1); i++)
        arr[i] = 1;

    for (int i = (c0 + c1); i < n; i++)
        arr[i] = 2;
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

    sort_fun(arr, n);

    //output sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}