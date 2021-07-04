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


vector <int> bottomView(Node *root);

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

        vector <int> res = bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    return 0;
}

void bottomview(Node * root, map<int,vector<int>>& m, int lev, int h_dist){
 
  if (root == NULL)
    return;

  if (m.find(h_dist) == m.end()) {   
    m[h_dist].push_back(lev);
    m[h_dist].push_back(root -> data);
  }

  else {
    if (m[h_dist][0] <= lev) {
      m[h_dist][0] = lev;
      m[h_dist][1]= root -> data;
    }
  }

  bottomview(root -> left, m, lev + 1, h_dist - 1);
  bottomview(root -> right, m, lev + 1, h_dist + 1);
}

vector <int> bottomView(Node *root)
{
 
    vector<int> v;
   if (root == NULL)
        return v;
        
    map<int,vector<int>> Map;
    bottomview(root,Map,1,0);
    for (auto it = Map.begin(); it != Map.end(); ++it)
      {
        v.push_back((it-> second)[1]);
      }
    return v;
}