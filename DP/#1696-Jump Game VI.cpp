// M1
// Using DP and Max Heap
// Faster than 56.91% (153 ms)

class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> dp(n);
        priority_queue<pair<int, int>> pq;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!pq.empty() and pq.top().second > i + k)
                pq.pop();
            dp[i] = nums[i];
            if (!pq.empty())
                dp[i] += pq.top().first;
            pq.push({dp[i], i});
        }
        return dp[0];
    }
};