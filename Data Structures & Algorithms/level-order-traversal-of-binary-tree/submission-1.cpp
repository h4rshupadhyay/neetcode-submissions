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
    vector<vector<int>> levelOrder(TreeNode* root) {
        deque<TreeNode*> q;
        vector<vector<int>> res;
        if(root) q.push_back(root);
        while(!q.empty()){
            vector<int> v;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* top = q.front();
                if(top->left){
                    q.push_back(top->left);
                }
                if(top->right) {
                    q.push_back(top->right);
                }
                v.push_back(top->val);
                q.pop_front();
            }
            res.push_back(v);
        }
        return res;
    }
};
