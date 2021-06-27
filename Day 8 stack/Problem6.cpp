// rain water trapping using stack

#include <bits/stdc++.h>
using namespace std;

int trappingWater(int arr[],int n)
{
    stack<int> s;

    int res=0;

    for(int i=0;i<n;i++)
    {
        while( s.empty() != 1 && arr[s.top()]<arr[i])
        {
            int prev = arr[s.top()];
            s.pop();

            if(s.empty())
            break;

            int l = i-s.top() - 1;

            int min_l = min(arr[s.top()],arr[i])-prev;
            res+=l*min_l;
        }
        s.push(i);
    }
    return res;
}

int main()
{
    int n;

    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << trappingWater(a, n) << endl;
}