// M1
// USing hashmap
// Faster than 51.1% (194ms)

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int temp = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i < nums.size() - 1 and nums[i] == nums[i + 1] and nums[i] == 0)
                return 1;
            temp = (temp % k + nums[i] % k) % k;
            if (temp == 0 and i >= 1)
                return 1;
            if (mp.count(temp))
            {
                if (i - mp[temp] >= 2)
                    return 1;
            }
            else
                mp[temp] = i;
        }
        return 0;
    }
};