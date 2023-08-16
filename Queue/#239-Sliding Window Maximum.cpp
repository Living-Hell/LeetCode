// M1
// Using Deque
// Faster than 82.4% (216ms)

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (!dq.empty() and dq.back() == i - k)
                dq.pop_back();
            if (!dq.empty() and nums[i] > nums[dq.front()])
            {
                while (!dq.empty() and nums[i] > nums[dq.front()])
                    dq.pop_front();
            }
            dq.push_front(i);
            if (i >= k - 1)
                ans.push_back(nums[dq.back()]);
        }
        return ans;
    }
};