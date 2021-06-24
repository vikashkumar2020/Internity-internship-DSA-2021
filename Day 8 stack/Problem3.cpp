// 3. Nearest smaller to right

#include<bits/stdc++.h>
using namespace std;

vector<int> nearestSmallerRight(int arr[],int n)
{
    vector<int> v(n);
    v[n-1]=-1;
    stack<int> s;
    s.push(arr[n-1]);
    for(int i=n-2;i>=0;i--)
    {
        // cout<<v[i]<<" ";
        while(s.empty()!=1 && arr[i]<=s.top())
        {
            s.pop();
        }

        if(s.empty())
        v[i]=-1;

        else
        v[i]=s.top();
       
        s.push(arr[i]);
    }
    return v;
}

int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i = 0;i<n;i++)
    {
        cin>> arr[i];
    }

    vector<int> res(n);

    res=nearestSmallerRight(arr,n);

    for(int i = 0;i<n;i++)
    {
        cout<<res[i]<<" ";
    }
}