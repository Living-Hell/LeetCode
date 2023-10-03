// M1
// Using hashmap
// Faster than 89.92% (128ms)

class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> mp;
        int count = 0, n = nums1.size();
        for (int i : nums1)
        {
            for (int j : nums2)
                mp[i + j]++;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                count += mp[-(nums3[i] + nums4[j])];
            }
        }
        return count;
    }
};