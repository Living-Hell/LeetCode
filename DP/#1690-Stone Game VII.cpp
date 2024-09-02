//M1
//Using recursion and memoisation
//Faster than 79.1% (114ms)

class Solution {
public:
    int dp[1001][1001];
    int solve(vector<int>& stones, int st, int end, int rem) {
        if (st > end or rem <= 0)
            return 0;
        int Bob = 0, Alice = 0;

        if(dp[st][end] != -1) return dp[st][end];

        int res1 =
            rem - stones[st] - solve(stones, st + 1, end, rem - stones[st]);
        int res2 =
            rem - stones[end] - solve(stones, st, end - 1, rem - stones[end]);

        return dp[st][end] = max(res1, res2);
    }

    int stoneGameVII(vector<int>& stones) {
        int rem = accumulate(stones.begin(), stones.end(), 0);
        memset(dp,-1,sizeof(dp));
        return solve(stones, 0, stones.size() - 1, rem);
    }
};
