// M1
// Using min max
// Faster than 94.14% (10ms)

class Solution
{
public:
    int smallestRangeI(vector<int> &nums, int k)
    {
        auto [mine, maxe] = minmax_element(nums.begin(), nums.end());
        return max(*maxe - *mine - 2 * k, 0);
    }
};