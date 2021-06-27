// the celebrity problem
#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> s;
    int C;
    for (int i = 0; i < n; i++)
        s.push(i);
    while (s.size() > 1)
    {
        int A = s.top();
        s.pop();
        int B = s.top();
        s.pop();
        if (M[A][B])
        {
            s.push(B);
        }
        else
        {
            s.push(A);
        }
    }

    if (s.empty())
        return -1;

    C = s.top();
    s.pop();

    for (int i = 0; i < n; i++)
    {
        if ((i != C) &&
            (M[C][i] ||
             !M[i][C]))
            return -1;
    }

    return C;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> M(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> M[i][j];
        }
    }
    cout << celebrity(M, n) << endl;
}