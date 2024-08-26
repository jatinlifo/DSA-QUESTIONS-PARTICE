#include<iostream>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> ans;

    // Helper function for postorder traversal
    void helperPostorder(Node* root) {
        if (root == nullptr) {
            return;
        }

        // Recursively visit each child
        for (Node* child : root->children) {
            helperPostorder(child);
        }

        // Add the current node's value after visiting children
        ans.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        ans.clear();  // Clear the result vector in case of multiple calls
        helperPostorder(root);  // Start the traversal from the root
        return ans;  // Return the postorder traversal result
    }
};

int main() {
    // Create nodes
    Node* child1 = new Node(5);
    Node* child2 = new Node(6);
    vector<Node*> children1 = {child1, child2};

    Node* rootChild1 = new Node(3, children1);
    Node* rootChild2 = new Node(2);
    Node* rootChild3 = new Node(4);
    vector<Node*> rootChildren = {rootChild1, rootChild2, rootChild3};

    Node* root = new Node(1, rootChildren);

    // Perform postorder traversal
    Solution solution;
    vector<int> result = solution.postorder(root);

    // Print the result
    for (int val : result) {
        cout << val << " ";
    }
    // Output: 5 6 3 2 4 1

    return 0;
}

/*
      
       1
     / | \
    3  2  4            
   / \
  5   6


*/