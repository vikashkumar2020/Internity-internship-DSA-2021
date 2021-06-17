// 3. inversion count

    #include<bits/stdc++.h>
    using namespace std;


    /*

    arr= {2,8,3,6,9,13,11,5}
                 /        \
        {2,8,3,6}        {9,13,11,5}
            / \               /    \
        {2,8}  {3,6}        {9,13} {11,5}
        /\       /\         / \      /  \
    {2}   {8}  {3} {6}     {9} {13} {11} {5}
      \  /       \ /        \  /      \ /
      {2,8}      {3,6}       {9,13}   {5,11}
         \        /             \      /
         {2,3,6,8}             {}


    */

    int merge(int arr[], int l, int mid, int r)
    {
        int x1 = mid-l+1;
        int x2 = r-mid;
        
        int count =0; // inversion count

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
            {
                arr[k++]=temp2[j++];
                count += (x1-i);  // counting inversion
            }
            
        }
        
        while(i<x1)
        arr[k++]=temp1[i++];
        while(j<x2)
        arr[k++]=temp2[j++];
	
    return count;
    }
    int inver(int arr[], int l, int r)
    {
        int count =0;
        if(l<r)
        {
      
        //code here
        int mid = l + (r-l)/2;
        
        count+=inver(arr,l,mid);
        count+=inver(arr,mid+1,r);
        count+=merge(arr,l,mid,r);
        }
        return count;
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

        cout<<inver(arr,0,n-1);

    }