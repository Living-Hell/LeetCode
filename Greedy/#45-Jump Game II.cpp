// M1
// Using greedy approach (kinda BFS)
// Faster than 74.55% (11 ms)

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        int steps = 0, maxJumps = 0, currMax = 0;
        for (int i = 0; i < n - 1; i++)
        {
            currMax = max(currMax, i + nums[i]);
            if (i == maxJumps)
            {
                maxJumps = currMax;
                steps++;
            }
        }
        return steps;
    }
};