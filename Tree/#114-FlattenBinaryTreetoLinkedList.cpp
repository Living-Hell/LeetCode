//M1
//Recursion
//Faster than 45.41% (12ms)

class Solution {
public:
    TreeNode* temp = NULL;
    
    void flatten(TreeNode* root) {
        
        if(!root) return;
        
        flatten(root->right);
        flatten(root->left);
        
        root->left = NULL;
        root->right = temp;
        
        temp = root;
        
    }
};

//M2
//Recursion
//Faster than 45.41% (12ms)

class Solution {
public:    
    void flatten(TreeNode* root) {
        
        if(!root) return;
        
        TreeNode* tempLeft = root->left;
        TreeNode* tempRight = root->right;
        
        root->left = NULL;
        
        flatten(tempLeft);
        flatten(tempRight);
        
        root->right = tempLeft;
        
        TreeNode* curr = root;
        
        while(curr->right!= NULL) curr = curr->right;
        
        curr->right = tempRight;
        
    }
};

//M3
//Morris Traversal
//Faster than 91.47% (4ms)

class Solution {
public:    
    void flatten(TreeNode* root) {
        
        if(!root) return;
        
        while(root){
            if(root->left){
                TreeNode* left = root->left;
                TreeNode* curr = left;
                while(curr->right) curr = curr->right;
                curr->right = root->right;
                root->left = NULL;
                root->right = left;
            }
            
            root = root->right;
        }
        
    }
};