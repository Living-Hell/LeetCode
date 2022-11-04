//M1
//Recursion and DFS
//Faster than 88.88% (23ms)

class Solution {
public:
    void addDepth(TreeNode* root, int depth, int val, int curr_depth){
       
        if(!root) return;
        
        //If current depth = depth -1, we have to add nodes next to or below this level
        if(curr_depth == depth-1){
            
            //Create the nodes to be added to the left and right at depth speciifed with given node value
            TreeNode* tleft = new TreeNode(val);
            TreeNode* tright = new TreeNode(val);
            
            //If we have left root we will have to add tleft to the left of the root and the existing tree which was present
            //there earlier to the left of the added node
            if(root->left){
                TreeNode* templ = root->left;
                root->left = tleft;
                tleft->left = templ;
            }
            
            //If not we simply add the tleft to the left of the root.
            else{
                root->left = tleft;
            }
            
            //If we have right root we will have to add tright to the right of the root and the existing tree which was present
            //there earlier to the right of the added node
            if(root->right){
                TreeNode* tempr = root->right;
                TreeNode* tright = new TreeNode(val);
                root->right = tright;
                tright->right = tempr;
            }
            
            //If not we simply add the tright to the right of the root.
            else{
                root->right = tright;
            }
            
            //If the given depth is equal to the depth of tree, all the nodes at this level will be leaf node
            //We simply have to add the newly created nodes to the left and right of the nodes at this depth
            if(!root->left && !root->right){
                root->left = tleft;
                root->right = tright;
            }
        }
        
        //Recursively call the left and right subtree of the current node while increasing the curr_depth by 1
        if(root->left) addDepth(root->left, depth, val, curr_depth+1);
        if(root->right) addDepth(root->right, depth, val, curr_depth+1);
       
    }
   
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        //if the given depth = 1 this means we have to create a new node with given value and add the whole tree to its left
        if(depth==1){
                TreeNode* temp = root;
                TreeNode* tleft = new TreeNode(val);
                tleft->left = temp;
                return tleft;
        }
        
        //Call the function with curr_depth = 1 passing all the required parameters
        addDepth(root, depth, val, 1);
        return root;
       
    }
};