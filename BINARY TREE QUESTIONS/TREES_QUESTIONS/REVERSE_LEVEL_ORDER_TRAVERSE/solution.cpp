// Given a binary tree of size n, find its reverse level order traversal. ie- the traversal must begin from the last level.

// Example 1:

// Input :
//         1
//       /   \
//      3     2

// Output: 
// 3 2 1
// Explanation:
// Traversing level 1 : 3 2
// Traversing level 0 : 1
// Example 2:

// Input :
//        10
//       /  \
//      20   30
//     / \ 
//    40  60

// Output: 
// 40 60 20 30 10
// Explanation:
// Traversing level 2 : 40 60
// Traversing level 1 : 20 30
// Traversing level 0 : 10

#include<iostream>
#include<vector>
#include<stack>
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

    vector<int> revereseLevelOrder(TreeNode* root){

        vector<int> ans;
        if(root == nullptr){
            return ans;
        }
        queue<TreeNode*> q;
        stack<TreeNode*> st;
        q.push(root);

        while(!q.empty()){
            TreeNode* f = q.front();
            q.pop();
            st.push(f);

            if(f->right){
                q.push(f->right);
            }
            if(f->left){
                q.push(f->left);
            }
        }

        while(!st.empty()){
            ans.push_back(st.top()->val);
            st.pop();
        }
        return ans;
    }
};

int main () {

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(60);

    Solution obj;
    vector<int> ans;
    ans = obj.revereseLevelOrder(root);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}