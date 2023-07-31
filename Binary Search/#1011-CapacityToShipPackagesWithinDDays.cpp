// M1
// Using Binary Search
// Faster than 99.06% (41ms)

class Solution
{
public:
    int helper(vector<int> &weights, int target)
    {
        int days = 1, weight = 0;
        for (int i : weights)
        {
            if (weight + i <= target)
                weight += i;
            else
            {
                days++;
                weight = i;
            }
        }
        return days;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        if (days > weights.size())
            return -1;
        int maxi = *max_element(weights.begin(), weights.end());
        int tsum = accumulate(weights.begin(), weights.end(), 0);
        int low = maxi, high = tsum;
        while (low < high)
        {
            int mid = (low + high) / 2;
            int ndays = helper(weights, mid);
            if (ndays > days)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};