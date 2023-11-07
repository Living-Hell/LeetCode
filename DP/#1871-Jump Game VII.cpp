// M1
// Using DP
// Faster than 68.19% (55ms)

class Solution
{
public:
    bool canReach(string s, int minj, int maxj)
    {
        int n = s.size();
        if (s[n - 1] == '1')
            return 0;
        vector<bool> ans(n, 0);
        ans[0] = 1;
        int left = 0, right = 0;

        for (int i = 0; i < n; i++)
        {
            if (!ans[i])
                continue;
            right = min(n - 1, i + maxj);
            for (int j = max(left, i + minj); j <= right; j++)
            {
                if (s[j] == '0')
                    ans[j] = 1;
            }
            left = right + 1;
        }
        return ans[n - 1];
    }
};