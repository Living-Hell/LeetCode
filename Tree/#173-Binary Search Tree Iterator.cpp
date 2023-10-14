// M1
// Using stack and in Avg Time O(1) and S.C. O(h)
// Faster than 33.47% (27 ms)

class BSTIterator
{
public:
    stack<TreeNode *> st;
    BSTIterator(TreeNode *root)
    {
        inorder(root);
    }

    void inorder(TreeNode *root)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
    }

    int next()
    {
        TreeNode *top = st.top();
        st.pop();
        inorder(top->right);
        return top->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};

// M2
// Using recursion in O(1) avg time and O(n) space
// Faster than 82.03% (20ms)

class BSTIterator
{
public:
    TreeNode *head;
    TreeNode *temp;
    int it;
    vector<int> io;
    BSTIterator(TreeNode *root)
    {
        head = temp = root;
        it = 0;
        inorder(temp);
    }

    void inorder(TreeNode *temp)
    {
        if (!temp)
            return;
        inorder(temp->left);
        io.push_back(temp->val);
        inorder(temp->right);
    }

    int next()
    {
        return io[it++];
    }

    bool hasNext()
    {
        if (it == io.size())
            return 0;
        return 1;
    }
};