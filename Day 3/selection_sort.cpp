// 3. Implementation of selection sort
#include<bits/stdc++.h>
using namespace std;

void selec_sort(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
    	int min=i;
    	for(int j=i+1;j<n;j++)
    	{
    		if(arr[j]<arr[min])
    		min=j;
    	}
    	swap(arr[i],arr[min]);
    }
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

    selec_sort(arr,n);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}