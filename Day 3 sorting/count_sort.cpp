// 2. Implementation of count sort
#include<bits/stdc++.h>
using namespace std;

void count_sort(int arr[], int n)
{
    int max = arr[0];

    for(int i=1;i<n;i++)
    {
        if(arr[i]>max)
        max = arr[i];
    }

    int *frequencyArray = new int[max+1];

    for(int i=0;i<max+1;i++)
    frequencyArray[i]=0;

for(int i=0;i<n;i++)
	{
		frequencyArray[arr[i]]++;
    }

int j = 0;

int i = 0;

while(i<max+1){
		
	while(frequencyArray[i]>0){
		
		arr[j] = i;
		j++;
		frequencyArray[i]--;
	}
	i++;
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

    count_sort(arr,n);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}