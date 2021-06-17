// implementation of merge sort

    #include<bits/stdc++.h>
    using namespace std;

    void merge(int arr[], int l, int mid, int r)
    {
        int x1 = mid-l+1;
        int x2 = r-mid;
        
        int temp1[x1];
        int temp2[x2];
        
        for(int i=0;i<x1;i++)
        temp1[i]=arr[l+i];
        
        for(int i=0;i<x2;i++)
        temp2[i]=arr[mid+1+i];
        
        int i=0,j=0,k=l;
        
        while(i<x1 && j<x2 )
        {
            if(temp1[i]<=temp2[j])
            arr[k++]=temp1[i++];
            else
            arr[k++]=temp2[j++];
        }
        
        while(i<x1)
        arr[k++]=temp1[i++];
        while(j<x2)
        arr[k++]=temp2[j++];
	
    }
    void mergeSort(int arr[], int l, int r)
    {
        if(l>=r)
        return;
        //code here
        int mid = l + (r-l)/2;
        
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
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

        mergeSort(arr,0,n-1);

        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }

    }