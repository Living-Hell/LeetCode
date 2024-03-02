// M1
// Recursion + memoisation
// Faster than 58.29% (56 ms)

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
class Solution
{
public:
    map<int, vector<TreeNode *>> mp;
    vector<TreeNode *> allPossibleFBT(int n)
    {
        if (n == 1)
            return {new TreeNode(0)};

        if (n % 2 == 0)
            return {};

        if (mp.contains(n))
            return mp[n];

        vector<TreeNode *> leftCh, rightCh, ans;

        for (int i = 1; i < n; i += 2)
        {
            leftCh = allPossibleFBT(i);
            rightCh = allPossibleFBT(n - i - 1);

            for (auto i : leftCh)
            {
                for (auto j : rightCh)
                {
                    ans.push_back(new TreeNode(0, i, j));
                }
            }
        }

        return mp[n] = ans;
    }
};