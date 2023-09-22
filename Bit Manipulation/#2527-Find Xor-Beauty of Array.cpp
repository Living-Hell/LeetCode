// M1
// Using bit manipulation (XOR)
// Faster than 58.23% (60ms)

class Solution
{
public:
    int xorBeauty(vector<int> &nums)
    {
        int ans = 0;
        for (const int &i : nums)
            ans ^= i;
        return ans;
    }
};