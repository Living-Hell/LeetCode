// M1
// Using quick Select: Avg ToC: O(n), Worsrt ToC: O(n2)
// TLE for the last TC
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = n - k;
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int pivot = nums[r], p = l;
            for (int i = l; i < r; i++)
            {
                if (nums[i] <= pivot)
                {
                    swap(nums[i], nums[p]);
                    p++;
                }
            }
            swap(nums[p], nums[r]);
            if (p < k)
                l = p + 1;
            else if (p > k)
                r = p - 1;
            else
                return nums[p];
        }
        return -1;
    }
};

// M2
// Using Priority Queue
// Faster than 39.55% (97ms)
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> pq;
        for (int i : nums)
            pq.push(i);
        while (--k)
        {
            pq.pop();
        }
        return pq.top();
    }
};