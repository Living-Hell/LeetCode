// M1
// Using DP
// Faster than 96.42% (36ms)

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int charge = 0, ind = 0, n = nums.size();
        if (n == 1)
            return 1;
        while (ind < n)
        {
            charge = max(charge, nums[ind]);
            if (charge > 0)
            {
                charge--;
                ind++;
            }
            else
                break;
        }
        return ind >= n - 1;
    }
};