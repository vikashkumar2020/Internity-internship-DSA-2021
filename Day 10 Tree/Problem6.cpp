// 6. Diagnoal traversal of a tree (gfg)

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



vector<int> diagonal(Node *root)
{
    vector<int> v;
    
    if(root==NULL)
    return v;
    
    queue<Node*> q;
    
    q.push(root);
    
    while(!q.empty())
    {
        
        int l = q.size();
        vector<int> t;
         
        while(l--)
        {
            Node *newnode = q.front();
            q.pop();
            
            while(newnode)
            {
                t.push_back(newnode->data);
                if(newnode->left)
                q.push(newnode->left);
                
                newnode = newnode->right;
            }
        }
        
        for(auto i : t)
        {
            v.push_back(i);
        }
        
    }    
    
    return v;
    
}

Node* buildTree(string str)
{
    // Corner Case
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



int main() {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        vector<int> diagonalNode = diagonal(root);
        for(auto i : diagonalNode)
        cout<<i<<" ";
        cout<<endl;
    return 0;
}
