// M1
// Using greedy approach
// Faster than 30.91% (19 ms)

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> ans(n, 1);
        for (int i = 1; i < n; i++)
        {
            if (ratings[i - 1] < ratings[i])
            {
                ans[i] = ans[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i + 1] < ratings[i])
            {
                ans[i] = ans[i + 1] + 1;
                if (i - 1 >= 0 and ratings[i - 1] < ratings[i])
                    ans[i] = max(ans[i], ans[i - 1] + 1);
            }
        }
        return accumulate(ans.begin(), ans.end(), 0);
    }
};