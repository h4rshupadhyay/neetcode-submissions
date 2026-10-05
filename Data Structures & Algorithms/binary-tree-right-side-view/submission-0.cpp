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
    vector<int> rightSideView(TreeNode* root) {
        deque<TreeNode*> q;
        if(root) q.push_back(root);
        vector<int> res;
        while(!q.empty()){
            int size = q.size();
            res.push_back(q.back()->val);
            for(int i=0;i<size;i++){
                TreeNode* top = q.front();
                if(top->left) q.push_back(top->left);
                if(top->right) q.push_back(top->right);
                q.pop_front();
            }
        }
        return res;
    }
};
