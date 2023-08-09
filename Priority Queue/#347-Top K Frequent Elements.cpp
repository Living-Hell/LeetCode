// M1
// USing sorting, 2 pointer and heap
// Faster than 81.75% (13 ms)

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int st = 0, end = 0;
        priority_queue<pair<int, int>> pq;
        while (st < n)
        {
            while (end < n and nums[end] == nums[st])
                end++;
            pq.push({end - st, nums[st]});
            st = end;
        }
        vector<int> ans;
        while (k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
