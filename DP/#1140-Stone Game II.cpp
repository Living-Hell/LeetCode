//M1
//Using recursion and memoization
//Faster than 75.65% (9ms)

class Solution {
public:
    int dp[101][101][3];
    int solve(vector<int>& piles, int i, int m, bool alice) {
        if (i >= piles.size())
            return 0;

        if (dp[i][m][alice] != -1)
            return dp[i][m][alice];

        int res = alice ? 0 : INT_MAX, rock = 0;

        int bound = min(2 * m, (int)piles.size() - i);

        for (int ind = 1; ind <= bound; ind++) {
            rock += piles[i + ind - 1];
            int newM = max(m, ind);
            if (alice) {
                res = max(res, rock + solve(piles, i + ind, newM, !alice));
            } else {
                res = min(res, solve(piles, i + ind, newM, !alice));
            }
        }
        return dp[i][m][alice] = res;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return solve(piles, 0, 1, 1);
    }
};
