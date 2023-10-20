// M1
// Using maths and while loop
// Faster than 100% (0ms)

class Solution
{
public:
    int brokenCalc(int startValue, int target)
    {
        int count = 0;
        while (target > startValue)
        {
            if (target & 1)
            {
                target++;
                count++;
            }
            target /= 2;
            count++;
        }
        count += startValue - target;
        return count;
    }
};