//M1
//Using recursion
//Faster than 74.32% (35ms)

TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root) return NULL;

    if(key > root->val) root->right = deleteNode(root->right, key);
    else if(key < root->val) root->left =  deleteNode(root->left,key);
    else{
        if(root->left == NULL) return root->right;
        else if(root->right == NULL) return root->left;
        
        TreeNode* temp = root->right;
        while(temp->left != NULL) temp = temp -> left;
        root->val = temp->val;
        
        root->right = deleteNode(root->right, root->val);
        
    }
    return root;
}