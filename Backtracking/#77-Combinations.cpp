// M1
// Recursion & Backtracking
// Faster than 16.67%% (610ms)

class Solution
{
public:
    void combination(vector<int> candidates, vector<int> &combo, vector<vector<int>> &res, int currIndex, int k)
    {

        if (combo.size() == k)
        {
            res.push_back(combo);
            return;
        }

        for (int i = currIndex; i < candidates.size(); i++)
        {
            combo.push_back(candidates[i]);
            combination(candidates, combo, res, i + 1, k);
            combo.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {

        vector<int> candidates(n);
        for (int i = 0; i < n; i++)
            candidates[i] = i + 1;
        vector<int> combo;
        vector<vector<int>> res;

        combination(candidates, combo, res, 0, k);

        return res;
    }
};

// M2
// Recursion & Backtracking
// Faster than 47.48%% (48ms)

class Solution
{
public:
    void combination(int curr, vector<int> &combo, vector<vector<int>> &res, int currIndex, int k, int n)
    {

        if (combo.size() == k)
        {
            res.push_back(combo);
            return;
        }

        for (int i = curr; i <= n; i++)
        {
            combo.push_back(i);
            combination(i + 1, combo, res, i + 1, k, n);
            combo.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {

        vector<int> combo;
        vector<vector<int>> res;

        combination(1, combo, res, 0, k, n);

        return res;
    }
};

// M3
// Backtracking using Recursion
// Faster than 88.38% (17ms)

class Solution
{
public:
    void helper(int n, int k, vector<int> &v, vector<vector<int>> &st, int ind)
    {
        if (ind > n)
            return;
        if (v.size() == k)
        {
            st.push_back(v);
            return;
        }
        for (int i = ind + 1; i <= n; i++)
        {
            v.push_back(i);
            helper(n, k, v, st, i);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> st;
        vector<int> v;
        helper(n, k, v, st, 0);
        return st;
    }
};