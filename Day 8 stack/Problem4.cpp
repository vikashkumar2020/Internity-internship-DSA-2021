// stock span problem

#include<bits/stdc++.h>
using namespace std;

    vector <int> calculateSpan(int price[], int n)
    {
       vector<int> v(n);
       
       stack<int> s;
       s.push(0);
       v[0]=1;
       
       for(int i=1;i<n;i++)
       {
           while(!s.empty() && price[i]>= price[s.top()])
           {
               s.pop();
           }
           
           v[i] = (s.empty()) ? (i + 1) : (i - s.top());
           
           s.push(i);
       }
       return v;
    }

int main()
{

		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		vector <int> s = calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
        
	return 0;
}