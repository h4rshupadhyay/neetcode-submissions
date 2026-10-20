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
    int counter = 0;
    void dfs(TreeNode* root,int maxArg){
        if(!root) return;
        if(root->val >= maxArg){
            counter++;
            maxArg = root->val;
        }

        dfs(root->left,maxArg);
        dfs(root->right,maxArg);
        cout << root->val << endl;
    }

    int goodNodes(TreeNode* root) {
        //approach: DFS with a max parameter, if a node is > max increment the counter and update max
        dfs(root,INT_MIN);
        return counter;
    }
};
