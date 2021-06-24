// area of histogram
#include <bits/stdc++.h>
using namespace std;


    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        
        stack<long long> s;
        s.push(-1);
        long long area = arr[0];
        long long i = 0;
        
        vector<long long> left_smaller(n, -1), right_smaller(n, n);
        
        while(i<n){
        while(!s.empty()&&s.top()!=-1&&arr[s.top()]>arr[i]){
            right_smaller[s.top()] = i;
            s.pop();
        }
        if(i>0&&arr[i]==arr[i-1]){
            left_smaller[i] = left_smaller[i-1];
        }
        else{
            left_smaller[i] = s.top();
        } 
        s.push(i);
        i++;
    }
      for(long long j = 0; j<n; j++){
          area = max(area, arr[j]*(right_smaller[j]-left_smaller[j]-1));
    }
    return area;
    }


int main()
 {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<getMaxArea(arr, n)<<endl;
	return 0;
}