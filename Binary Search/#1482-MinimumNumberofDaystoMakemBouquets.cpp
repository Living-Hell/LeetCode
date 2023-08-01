// M1
// Using Binary Search
// Faster than 98.04% (132ms)

class Solution
{
public:
    int helper(vector<int> &bDay, int k, int day, int n)
    {
        int bouq = 0, days = 0;
        for (int i = 0; i < n; i++)
        {
            if (bDay[i] <= day)
                days++;
            else
            {
                bouq += days / k;
                days = 0;
            }
        }
        bouq += days / k;
        return bouq;
    }
    int minDays(vector<int> &bDay, int m, int k)
    {
        int n = bDay.size();
        if (1ll * n < 1ll * m * k)
            return -1;
        int low = *min_element(bDay.begin(), bDay.end());
        int high = *max_element(bDay.begin(), bDay.end());

        while (low < high)
        {
            int mid = (low + high) / 2;
            int bouquet = helper(bDay, k, mid, n);
            if (bouquet >= m)
                high = mid;
            else
                low = mid + 1;
        }
        return high;
    }
};