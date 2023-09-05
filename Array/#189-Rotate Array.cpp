// M1
// Using Array reversal
// Faster than 97.84% (15ms)

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (k > n)
            k %= n;
        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
    }
};