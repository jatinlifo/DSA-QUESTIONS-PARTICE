// Given the root of a binary tree, invert the tree, and return its root.
// Example 1:

// Input: root = [4,2,7,1,3,6,9]
// Output: [4,7,2,9,6,3,1]
// Example 2:
// Input: root = [2,1,3]
// Output: [2,3,1]
// Example 3:

// Input: root = []
// Output: []
 
// Constraints:

// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100

#include<iostream>
#include<queue>

using namespace std;

class TreeNode{
    public:

    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

class Solution{
    public:
    
    void print(TreeNode* root){

        if(root == nullptr){
            return;
        }
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            cout<<node->val<<" ";
            
            if(node != nullptr){
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
            }
        }
    }
    TreeNode* invertBinaryTree(TreeNode* root){

        if(root == nullptr){
            return root;
        }

        swap(root->left,root->right);
        invertBinaryTree(root->left);
        invertBinaryTree(root->right);

        return root;
    }

};


int main () {

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    Solution obj;
    obj.print(root);
    
    cout<<endl;
    cout<<"After inverting : ";
    cout<<endl;

    obj.invertBinaryTree(root);
    obj.print(root);
    return 0;
}