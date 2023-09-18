// M1
// Using greedy approach
// Faster than 100% (0ms)

class Solution
{
public:
    int monotoneIncreasingDigits(int n)
    {
        string num = to_string(n);
        int len = num.size();
        int i = 0;
        while (i < num.size() - 1 and num[i] <= num[i + 1])
            i++;
        if (i == len - 1)
            return n;
        while (i > 0 and num[i - 1] == num[i])
            i--;
        num[i]--;
        i++;
        int counter = 9 - len + i;
        for (; i < num.size(); i++)
            num[i] = '0' + 9;
        int ans = stoi(num);
        return ans;
    }
};