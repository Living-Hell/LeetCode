// M1
// Using Hashmap
// Faster than 92.57% (8 ms)

class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }

        vector<vector<int>> res;

        while (mp.size())
        {
            vector<int> temp, toErase;
            for (auto &[a, b] : mp)
            {
                temp.push_back(a);
                b--;
                if (b == 0)
                    toErase.push_back(a);
            }
            for (auto i : toErase)
                mp.erase(i);
            res.push_back(temp);
        }
        return res;
    }
};