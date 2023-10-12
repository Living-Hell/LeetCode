// M1
// Using recursion + memoization
// Faster than 68.48% (359 ms)

class Solution
{
public:
    int dp[1001][1001];
    int solve(vector<int> &arr, int i, int j, unordered_map<int, int> &mp)
    {
        if (dp[i][j] != -1)
            return dp[i][j];
        if (mp.find(arr[i] + arr[j]) == mp.end())
            return 0;
        return dp[i][j] = 1 + solve(arr, j, mp[arr[i] + arr[j]], mp);
    }
    int lenLongestFibSubseq(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, int> mp;
        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < n; i++)
        {
            mp[arr[i]] = i;
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (mp.find(arr[i] + arr[j]) != mp.end())
                {
                    int temp = 2 + solve(arr, i, j, mp);
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};

// M2
// Using binary search
// Faster than 5.05% (1868 ms)

class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        int n = arr.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int a = arr[i], b = arr[j], c = a + b, count = 2;
                while (lower_bound(arr.begin(), arr.end(), c) != arr.end())
                {
                    c = *lower_bound(arr.begin(), arr.end(), c);
                    if (c != (a + b))
                        break;
                    a = b, b = c, c = a + b;
                    count++;
                }
                ans = count > 2 ? max(ans, count) : ans;
            }
        }
        return ans;
    }
};