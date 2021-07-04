// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

    void left_view(Node *root, vector<int> &v)
    {
        if(root==NULL)
        return;
        if(root->left!=NULL)
        {
            v.push_back(root->data);
            left_view(root->left,v);
        }
        else if(root->right!=NULL)
        {
            v.push_back(root->data);
            left_view(root->right,v);
        }
    }
    void right_view(Node *root, vector<int> &v)
    {
        if(root==NULL)
        return;
        if(root->right!=NULL)
        {
            right_view(root->right,v);
            v.push_back(root->data);
        }
        else if(root->left!=NULL)
        {
            right_view(root->left,v);
            v.push_back(root->data);
        }
    }
    
    void leaf(Node *root,vector<int> &v)
    {
        if(root==NULL)
        return;
        
        leaf(root->left,v);
        
        if(root->left==NULL && root->right==NULL)
        v.push_back(root->data);
        
        leaf(root->right,v);
    }

    vector <int> printBoundary(Node *root)
    {
        vector<int> v;
        
        if(root==NULL)
        return v;
        
        v.push_back(root->data);
        
        left_view(root->left,v);
        
        leaf(root->left,v);
        leaf(root->right,v);
        
        right_view(root->right,v);
        
        return v;
    }

int main() {
   
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        vector <int> res = printBoundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    
    return 0;
}