// M1
// Using recursion and intuition
// Faster than 32.53% (16 ms)

class Solution
{
public:
    int nextInd(vector<int> &nums, int i, bool dir)
    {
        int n = nums.size();

        if (nums[i] >= 0 != dir)
            return -1;

        int nexti = ((i + nums[i]) % n + n) % n;
        if (nexti == i)
            return -1;

        return nexti;
    }
    bool circularArrayLoop(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                return 0;
        }

        int slow, fast;
        for (int i = 0; i < n; i++)
        {
            bool dir = nums[i] >= 0;
            slow = i, fast = i;
            while (1)
            {
                slow = nextInd(nums, slow, dir);
                if (slow == -1)
                    break;

                fast = nextInd(nums, fast, dir);
                if (fast == -1)
                    break;

                fast = nextInd(nums, fast, dir);
                if (fast == -1)
                    break;

                if (slow == fast)
                    return 1;
            }
        }
        return 0;
    }
};