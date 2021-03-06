// 1. Left view of a Tree (gfg practice)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
vector<int> leftView(Node *root)
{
   vector<int> v;
   
   if(root==NULL)
   return v;
   
   queue<Node*> q;
   q.push(root);
   
   while(!q.empty())
   {
       int n = q.size();
       while(n--)
       {
           Node* x = q.front();
            q.pop();
            
            if (n == 0) {
                v.push_back(x->data );
            }
             if (x->right)
                q.push(x->right);
                
            if (x->left)
                q.push(x->left);
                
       }
       
   }
   return v;
}

    Node* buildTree(string str)
{
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    Node* root = newNode(stoi(ip[0]));

    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        Node* currNode = queue.front();
        queue.pop();

        string currVal = ip[i];

        if(currVal != "N") {

            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }

        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
        if(currVal != "N") {

            currNode->right = newNode(stoi(currVal));

            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main()
{
    string s;
        getline(cin,s);
        Node* root = buildTree(s);

        vector<int> vec = leftView(root);
        for(int x : vec){
            cout<<x<<" ";
        }
        cout << endl;
    
    return 0;
}