// nearest greater left

#include <bits/stdc++.h>
using namespace std;
 
vector<int> prevGreater(int arr[], int n)
{
    vector<int> v;
    stack<int> s;

    for (int i = 0; i < n; i++) {
 
        while (s.empty() == false && s.top() < arr[i])
            s.pop();
 
        s.empty() ? v.push_back(-1) : v.push_back(s.top()) ;
 
        s.push(arr[i]);
    }
    return v;
}


int main()
{
    int n;
    cin>>n;
    int arr[n];

    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int> v;
    v=prevGreater(arr, n);

    for(auto i:v)
    {
        cout<<i<<" ";
    }
    return 0;
}