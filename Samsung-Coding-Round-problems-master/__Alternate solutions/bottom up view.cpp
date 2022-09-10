// C++ Program to print Bottom View of Binary Tree
#include<bits/stdc++.h>
using namespace std;

// Tree node class
struct Node
{
	int data; //data of the node
	int hd; //horizontal distance of the node
	Node *left, *right; //left and right references

	// Constructor of tree node
	Node(int key)
	{
		data = key;
		hd = INT_MAX;
		left = right = NULL;
	}
};

//complete this function
void bottomView(Node *root)
{
    int i = 0 ;
    root->hd = i ;
    queue<Node *> q ;
    q.push(root) ;

    map<int,int> mp ;
    while(!q.empty())
    {
        Node* temp = q.front() ;
        q.pop() ;
        i = temp->hd ;
        mp[i] = temp->data ;

        if(temp->left)
        {
            temp->left->hd = temp->hd -1 ;
            q.push(temp->left) ;
        }
        if(temp->right)
        {
            temp->right->hd = temp->hd +1 ;
            q.push(temp->right) ;
        }
    }
    map<int,int>::iterator it ;
    for(it = mp.begin(); it!=mp.end() ;it++)
        cout<<(*it).second<<" ";
}

int main()
{
	Node *root = new Node(20);
	root->left = new Node(8);
	root->right = new Node(22);
	root->left->left = new Node(5);
	root->left->right = new Node(3);
	root->right->left = new Node(4);
	root->right->right = new Node(25);
	root->left->right->left = new Node(10);
	root->left->right->right = new Node(14);
	cout << "Bottom view of the given binary tree :\n" ;
	bottomView(root);
	return 0;
}
