//M1
//Recursion & Divide and Conquer
//Faster than 27.44% (177ms)

class Solution {
public:
    TreeNode* MaxBT(vector<int>& nums, int start, int end){
        
        if(start>end) return NULL;
        
        int ind = max_element(nums.begin()+start,nums.begin()+end+1) - nums.begin();
        
        TreeNode* root = new TreeNode(nums[ind]);
        
        root->left = MaxBT(nums, start, ind-1);
        root->right = MaxBT(nums, ind+1, end);
        
        return root;
        
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        int n = nums.size();
        
        return MaxBT(nums,0,n-1);
        
    }
};

//M1
//Recursion & Divide and Conquer using Pointer and Array
//Faster than 52% (150ms)

class Solution {
public:
    void MaxBT(TreeNode* root, int* arr, int start, int end){
        
        int index = distance(arr,max_element(arr+start,arr+end));
        root->val = arr[index];
        
        if(index>start){
            root->left = new TreeNode();
            MaxBT(root->left, arr, start, index);
        }
        
        if(index+1<end){
            root->right = new TreeNode();
            MaxBT(root->right, arr, index+1, end);
        }
        
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        int* arr = &nums[0];
        TreeNode* root = new TreeNode();
        
        MaxBT(root, arr, 0, nums.size());
        
        return root;
        
    }
};