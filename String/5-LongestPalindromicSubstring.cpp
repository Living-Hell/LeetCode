// M1
// Using DP
// Faster than 24.69% (360ms)

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
            dp[i][i] = 1;

        int st = 0, end = 0;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; i + j < n; j++)
            {
                if (i == 1 && s[j] == s[j + i] && dp[j][i + j - 1])
                {
                    dp[j][i + j] = 1;
                    st = j;
                    end = i + j;
                }
                else if (s[j] == s[j + i] && dp[j + 1][i + j - 1])
                {
                    dp[j][i + j] = 1;
                    st = j;
                    end = i + j;
                }
            }
        }

        string ans = s.substr(st, end - st + 1);
        return ans;
    }
};
