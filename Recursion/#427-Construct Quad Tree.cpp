//M1
//Using recursion
//Faster than 90.10% (7ms)

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
    Node *helper(vector<vector<int>> &grid, int rSt, int rEnd, int cSt, int cEnd){
        Node *root = new Node();
        bool check = true;
        int val = grid[rSt][cSt];
        for(int i = rSt; i<rEnd; i++){
            for(int j=cSt; j<cEnd; j++){
                if(grid[i][j] != val)
                    check = false;
            }
        }
        if(check){
            root->isLeaf = true;
            root->val = val;
            return root;
        }
        root->topLeft = helper(grid, rSt, rSt + (rEnd-rSt)/2, cSt, cSt + (cEnd-cSt)/2);
        root->bottomLeft = helper(grid, rSt + (rEnd-rSt)/2, rEnd, cSt, cSt + (cEnd-cSt)/2);
        root->topRight = helper(grid, rSt, rSt + (rEnd-rSt)/2, cSt + (cEnd-cSt)/2, cEnd);
        root->bottomRight = helper(grid, rSt + (rEnd-rSt)/2, rEnd, cSt + (cEnd-cSt)/2, cEnd);
        return root;
    }
    Node* construct(vector<vector<int>>& grid) {
        return helper(grid,0,grid.size(),0,grid.size());
    }
};
