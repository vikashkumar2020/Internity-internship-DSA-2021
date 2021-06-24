// 2. Nearest smaller to left

#include<bits/stdc++.h>
using namespace std;

vector<int> nearestSmallerLeft(int arr[],int n)
{
    vector<int> v(n);
    v[0]=-1;
    stack<int> s;
    s.push(arr[0]);
    for(int i=1;i<n;i++)
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

    res=nearestSmallerLeft(arr,n);

    for(int i = 0;i<n;i++)
    {
        cout<<res[i]<<" ";
    }
}