// M1
// Using hashmap and converting to subarrays with sum k problem
// Faster than 41.76% (160ms)

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] & 1)
                nums[i] = 1;
            else
                nums[i] = 0;
        }

        int count = 0, sum = 0;
        unordered_map<int, int> m;

        m[0]++;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (m.find(sum - k) != m.end())
                count += m[sum - k];
            m[sum]++;
        }

        return count;
    }
};