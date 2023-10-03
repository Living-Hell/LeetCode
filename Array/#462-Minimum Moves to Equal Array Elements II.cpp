// M1
// Using sorting
// Faster than 13.42% (30ms)

class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int med = nums[n / 2];
        int ans = 0;
        for (int i : nums)
            ans += abs(i - med);
        return ans;
    }
};

// M2
// Using nth_element function
// Faster than 72.52% (8 ms)

class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + (n / 2), nums.end());
        int med = nums[n / 2];
        int ans = 0;
        for (int i : nums)
            ans += abs(i - med);
        return ans;
    }
};