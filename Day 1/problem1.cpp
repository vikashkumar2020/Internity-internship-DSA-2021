//1. Find length of an array

#include <iostream>
using namespace std;

int main()
{
	// your code goes here

	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};

	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Size of array is " << n;
	return 0;
}