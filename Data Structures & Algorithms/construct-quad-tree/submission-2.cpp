/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* buildNode(vector<vector<int>> &grid,int x1,int y1,int x2,int y2){
        if(x1==x2 && y1 == y2){
            return new Node(grid[x1][y1],1);
        }
        
        Node* node= new Node(0,0);
        //build tl
        node->topLeft = buildNode(grid,x1,y1,(x1+x2)/2,(y1+y2)/2);
        //build br
        node->topRight = buildNode(grid,x1,(y1+y2)/2+1,(x1+x2)/2,y2);
        //build bl
        node->bottomLeft = buildNode(grid,(x1+x2)/2+1,y1,x2,(y1+y2)/2);
        //build tr
        node->bottomRight = buildNode(grid,(x1+x2)/2+1,(y1+y2)/2+1,x2,y2);
        
        //logic to merge uniform leaves
        if(node->isLeaf != true){
            //if node is not a leaf then all childrens must exist
            if(node->topLeft->isLeaf && node->topRight->isLeaf && node->bottomLeft->isLeaf && node->bottomRight->isLeaf && node->topLeft->val == node->topRight->val && node->topRight->val == node->bottomLeft->val && node->bottomLeft->val == node->bottomRight->val){
                node->isLeaf = true;
                node->val = node->topLeft->val;
                delete node->topLeft;
                delete node->topRight;
                delete node->bottomLeft;
                delete node->bottomRight;
                node->topLeft = nullptr;
                node->topRight = nullptr;
                node->bottomLeft = nullptr;
                node->bottomRight = nullptr;
            }
        }

        return node;
    }
    Node* construct(vector<vector<int>>& grid) {
        // cout << grid.size() << grid[0].size();
        Node* root = buildNode(grid,0,0,grid.size()-1,grid[0].size()-1);
        return root;
        // return nullptr;
    }
};