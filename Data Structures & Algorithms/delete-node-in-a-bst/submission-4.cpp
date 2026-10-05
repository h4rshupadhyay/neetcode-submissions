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
    TreeNode* helper(TreeNode* root){
        TreeNode* predecessor = root->left;
        while(predecessor && predecessor->right){
            predecessor = predecessor->right;
        }

        if(predecessor) predecessor->right = root->right;
        if(root->left) return root->left;
        else return root->right;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* curr = root;
        TreeNode* prev = nullptr;
        while(curr && curr->val != key){
            prev = curr;
            if(key > curr->val) curr = curr->right;
            else curr = curr->left;
        }
        if(!curr || curr->val != key) return root;
        if(prev){
            if(prev->right && prev->right == curr){
                prev->right = helper(curr);
            }
            else prev->left = helper(curr);
        }
        else {
            return helper(curr);
        }
        return root;
    }
};