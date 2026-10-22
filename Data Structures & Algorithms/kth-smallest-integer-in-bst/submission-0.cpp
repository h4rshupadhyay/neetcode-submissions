/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int key;
    int counter = 0;
    int ans = 0;
    void dfs(TreeNode* root){
        if(!root) return;

        dfs(root->left);
        // cout << "k: " <<counter++ << " val:" << root->val << "\n";
        if(key==++counter) ans = root->val; 
        dfs(root->right);

    }
    int kthSmallest(TreeNode* root, int k) {
        key = k;
        dfs(root);
        return ans;
    }
};
