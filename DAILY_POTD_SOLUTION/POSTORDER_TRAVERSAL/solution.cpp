// //PROBLEM NO.  145

// Given the root of a binary tree, return the postorder traversal of its nodes' values.
// Example 1:
// Input: root = [1,null,2,3]   
/*
          1
       /    \
    NULL     2
          /    \
         3      NULL
       /   \
      NULL  NULL

*/
// Output: [3,2,1]
// Example 2:
// Input: root = []
// Output: []

#include<iostream>
#include<vector>

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
    
    vector<int> ans;
    void helperPostorder(TreeNode* root)
    {
        if(root == nullptr){
            return;
        }
        helperPostorder(root->left);
        helperPostorder(root->right);
        ans.push_back(root->val);
    }
    vector<int> postorder(TreeNode* root)
    {
        if(root == nullptr){
            return {};
        }
        helperPostorder(root);

        return ans;
    }
};

int main ()
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution obj;
    vector<int> ans = obj.postorder(root);

    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}