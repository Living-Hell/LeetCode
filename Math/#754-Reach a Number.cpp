// M1
// Using Maths
// FAster than 54.44% (2ms)

class Solution
{
public:
    int reachNumber(int target)
    {
        target = abs(target);
        long long int curr, total;
        curr = ceil((-1.0 + sqrt(1 + 8.0 * target)) / 2); // check this
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