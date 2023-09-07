// M1
// Through bit manipulation using xor
// Faster than 98.23% (3ms)

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        long long xall;
        long long pw = pow(2, 32);
        for (int num : nums)
        {
            xall ^= (num + pw);
        }
        long long rmst = xall & ~(xall - 1);
        long long first = 0, second = 0;
        for (int num : nums)
        {
            if (rmst & (num + pw))
                first ^= num + pw;
            else
                second ^= num + pw;
        }
        return {(int)(first - pw), (int)(second - pw)};
    }
};