// M1
// Using recursion
// Faster than 100% (0ms)

class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        if (n == 1)
            return 0;
        if (n == 2)
            return k == 1 ? 0 : 1;
        int md = k & 1;
        int up = kthGrammar(n - 1, (k + 1) / 2);
        int ans = 0;
        if (up & md or (!up and !md))
            ans = 1;
        return ans;
    }
};