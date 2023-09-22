// M1
// Using dfs
// Faster than 48.97% (114ms)

class Solution
{
public:
    int arrayNesting(vector<int> &nums)
    {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            int next = i, count = 0;
            while (nums[next] >= 0)
            {
                count++;
                int t = nums[next];
                nums[next] = -1;
                next = t;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};

// M2
// Using sets
// Faster than 16.64% (254ms)

class Solution
{
public:
    int arrayNesting(vector<int> &nums)
    {
        int ans = 0;
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++)
        {
            int next = i, count = 0;
            while (!st.count(next))
            {
                st.insert(next);
                count++;
                next = nums[next];
            }
            ans = max(ans, count);
        }
        return ans;
    }
};
