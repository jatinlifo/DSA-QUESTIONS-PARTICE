#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class TreeNode{
    public:

    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};

class Solution{
    public:

    vector<vector<int> >  levelOrderTraverse(TreeNode* root)
    {
        vector<vector<int> > res;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        vector<int> temp;

        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if(node != NULL)
            {
                temp.push_back(node->val);

                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
            }
            else{
                res.push_back(temp);
                temp.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
        }
        return res;
    }
};

int main ()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    Solution obj;
    vector<vector<int>> ans = obj.levelOrderTraverse(root);

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;

}