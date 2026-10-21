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
    vector<int> inorder;
    void dfs(TreeNode* root){
        //serialize the inorder and check if it's sorted
        if(!root) return;

        dfs(root->left);
        // cout << root->val << " ";
        inorder.push_back(root->val);
        dfs(root->right);
    }

    bool isStrictlySorted(){
        return is_sorted(inorder.begin(),inorder.end()) && adjacent_find(inorder.begin(),inorder.end()) == inorder.end();
    }
    bool isValidBST(TreeNode* root) {
        dfs(root);
        return isStrictlySorted();
    }
};
