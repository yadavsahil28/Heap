#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

*************************************************************/
void minHeapUsingPreorder(BinaryTreeNode* root, vector<int>& arr, int& i){
	if(root == NULL)
		return;
	
	root->data = arr[i++];
	minHeapUsingPreorder(root->left, arr, i);
	minHeapUsingPreorder(root->right, arr, i);
}

void inorderTraversal(BinaryTreeNode* root, vector<int>& arr)
{
    if (root == NULL)
        return;
 
    // first recur on left subtree
    inorderTraversal(root->left, arr);
 
    // then copy the data of the node
    arr.push_back(root->data);
 
    // now recur for right subtree
    inorderTraversal(root->right, arr);
}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	vector<int> arr;
	inorderTraversal(root, arr);

	int i = 0;
	minHeapUsingPreorder(root, arr, i);
	return root;
}
