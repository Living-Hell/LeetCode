//M1
//Using DP (recursion + memoisation)
//Faster than 42.28% (97ms)

class Solution {
public:
    long long dp[101][10002];
    long long helper(vector<int>& robot, vector<int>& pos, int i, int j) {
        if (i == robot.size())
            return 0;
        if( j == pos.size())
            return LONG_MAX;

        long long res = LLONG_MAX;
        if (dp[i][j] != -1)
            return dp[i][j];

        long long factoryOpted = helper(robot, pos, i + 1, j + 1);

        if(factoryOpted != LLONG_MAX)
            res = abs(robot[i] - pos[j]) + factoryOpted;

        res = min(res, helper(robot,pos,i,j+1));

        return dp[i][j] = res;
    }
    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        vector<int> pos;
        for (auto j : factory) {
            for (int i = 0; i < j[1]; i++)
                pos.push_back(j[0]);
        }
        sort(pos.begin(), pos.end());
        memset(dp, -1, sizeof(dp));
        long long res = helper(robot, pos, 0, 0);

        return res;
    }
};
