// M1 
// Using lambda function and hashmap
// Faster than 39.16% (8ms)

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int& i : nums)
            mp[i]++;
        sort(nums.begin(), nums.end(), [&](const int& a, const int& b) {
            if (mp[a] == mp[b])
                return a > b;
            return mp[a] < mp[b];
        });
        return nums;
    }
};
