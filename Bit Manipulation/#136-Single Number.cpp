// M1
// Through bit manipulation using xor
// Faster than 90.83% (11ms)

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int xorall = 0;
        int offset = 3e4;
        for (int i : nums)
            xorall ^= (i + offset);
        return xorall - offset;
    }
};