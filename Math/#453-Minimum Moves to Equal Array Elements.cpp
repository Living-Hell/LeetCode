// M1
// Using maths
// Faster than 82.88% (25ms)

class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        int minm = *min_element(nums.begin(), nums.end());
        int ans = 0;
        for (int i : nums)
            ans += i - minm;
        return ans;
    }
};