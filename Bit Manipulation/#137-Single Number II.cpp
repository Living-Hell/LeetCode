// M1
// Using Bit Manipulation and modding sum of bits by 3
// Faster than 84.67% (4ms)

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        long long bitmap[64] = {0};
        for (long long num : nums)
        {
            int i = 0;
            num += pow(2, 32);
            while (num > 0)
            {
                bitmap[i] += num % 2;
                num /= 2;
                if (bitmap[i] == 3)
                    bitmap[i] = 0;
                i++;
            }
        }
        long long ans = 0;
        for (int i = 0; i < 64; i++)
        {
            ans += pow(2, i) * bitmap[i];
        }
        ans -= pow(2, 32);
        return (int)ans;
    }
};