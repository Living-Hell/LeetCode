// M1
// Using bit manipulation and maths
// Faster than 49.47% (8ms)

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        // Result = BitwiseAnd from 1 to right - BitwiseAnd from 1 to left
        int count = 0;
        while (left != right)
        {
            count++;
            left >>= 1;
            right >>= 1;
        }
        right <<= count;
        return right;
    }
};