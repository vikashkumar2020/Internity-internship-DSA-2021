// 11. minimum number of deletion required to balance the parantesis
#include<bits/stdc++.h>
using namespace std;


int minDelValidParen(string s)
{
    stack<int> st;

    for(int i = 0; i < s.size(); i++){
         if(s[i] == '(')st.push(i);
         else if(s[i] == ')'){
            if(!st.empty())st.pop();
            else s[i] = '*';
         }
      }

      while(!st.empty()){
         s[st.top()] = '*';
         st.pop();
      }
      string ans = "";
     for(int i = 0; i < s.size(); i++){
        if(s[i] != '*')ans += s[i];
      }

      return s.size()-ans.size();
}

int main()
{
    string s;
    cin>>s;

    int n = minDelValidParen(s);

    cout<<"minimum req. : "<<n;
}