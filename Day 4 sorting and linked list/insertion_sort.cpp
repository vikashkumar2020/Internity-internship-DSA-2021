#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertionSort(int arr[], int n)
    {
        for(int i=1;i<n;i++)
        {
            int key = arr[i];
            int j = i-1;
            while(j>=0 && arr[j]>key)
            {
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
        }
    }

int main()
{
    int arr[1000],n,i;


    scanf("%d",&n);

    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}


