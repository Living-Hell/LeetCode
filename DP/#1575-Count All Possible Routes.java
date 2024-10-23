//M1
//Using DP (recursion + memoisation)
//Faster than 94.02% (40ms)

class Solution {
    int dp[][];
    int MOD = 1000000007;

    public int helper(int[] locations, int curr, int finish, int currFuel) {
        if (currFuel < 0)
            return 0;

        if (dp[curr][currFuel] != -1)
            return dp[curr][currFuel];

        int res = curr == finish ? 1 : 0;

        for (int i = 0; i < locations.length; i++) {
            if (i != curr) {
                int fuelCost = Math.abs(locations[curr] - locations[i]);
                if (fuelCost <= currFuel) {
                    res = (res + helper(locations, i, finish, currFuel - fuelCost)) % MOD;
                }
            }
        }
        return dp[curr][currFuel] = res;
    }

    public int countRoutes(int[] locations, int start, int finish, int fuel) {
        dp = new int[locations.length + 1][fuel + 1];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        return helper(locations, start, finish, fuel);
    }
}
