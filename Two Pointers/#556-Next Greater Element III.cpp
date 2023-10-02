// M1
// Using 2 pointers
// Faster than 100% (0ms)

class Solution
{
public:
    int nextGreaterElement(int n)
    {
        string num = to_string(n);
        if (num.size() > 10)
            return -1;
        int len = num.size();
        for (int i = len - 2; i >= 0; i--)
        {
            int t = INT_MAX, ind = i;
            for (int j = i + 1; j < len; j++)
            {
                if (num[j] > num[i] and num[j] < t)
                {
                    t = num[j];
                    ind = j;
                }
            }
            if (ind != i)
            {
                swap(num[i], num[ind]);
                for (int j = i + 1; j < len; j++)
                {
                    int temp = INT_MAX, l = j;
                    for (int k = j + 1; k < len; k++)
                    {
                        if (num[j] > num[k] and num[k] < temp)
                        {
                            temp = num[k];
                            l = k;
                        }
                    }
                    if (l != j)
                    {
                        swap(num[j], num[l]);
                    }
                }
                if (stol(num) > INT_MAX)
                    return -1;
                return stol(num);
            }
        }

        return -1;
    }
};