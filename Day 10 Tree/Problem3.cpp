// 3. Top view of a binary tree

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

Node* buildTree(string str)
{
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    Node* root = newNode(stoi(ip[0]));

    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        Node* currNode = queue.front();
        queue.pop();

        string currVal = ip[i];

        if (currVal != "N") {

            currNode->left = newNode(stoi(currVal));

            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        if (currVal != "N") {

            currNode->right = newNode(stoi(currVal));

            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

vector<int> topView(Node *root)
    {
        vector<int> v;
        vector<int> res;
        queue<pair<Node*, int> > q;
        q.push(make_pair(root, 0));
        
         int hd = 0, l = 0, r = 0;
         stack<int> left;
         
          Node* node;
          
          while (q.size()) {
 
            node = q.front().first;
            hd = q.front().second;
 
            if (hd < l) {
                left.push(node->data);
                l = hd;
            }
            else if (hd > r) {
                v.push_back(node->data);
                r = hd;
            }
 
            if (node->left) {
                q.push(make_pair(node->left, hd - 1));
            }
            if (node->right) {
                q.push(make_pair(node->right, hd + 1));
            }
 
            q.pop();
        }
        
        while (left.size()) {
            res.push_back(left.top());
            left.pop();
        }
        res.push_back(root->data);
        
        for (auto x : v) {
            res.push_back(x);
        }
        return res;
    }

int main()
{
    string treeString;
    getline(cin, treeString);

    Node *root = buildTree(treeString);
        vector<int> vec = topView(root);
        for(int x : vec)
    cout<<x<<" ";
        cout<<endl;
    return 0;

}