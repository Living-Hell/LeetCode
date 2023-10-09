// M1
// Using Maths
// FAster than 100% (0ms)

class Solution
{
public:
    int reachNumber(int target)
    {
        target = abs(target);
        long long int curr, total;
        curr = ceil(sqrt(2 * target + 0.25) - 0.5);
        total = curr * (curr + 1) / 2;
        cout << total;
        if (total == target)
            return curr;
        long long int res = total - target;
        if (res % 2 == 0)
            return curr;
        else
        {
            if (curr & 1)
                return curr + 2;
            else
                return curr + 1;
        }
    }
};