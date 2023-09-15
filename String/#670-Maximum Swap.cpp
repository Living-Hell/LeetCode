// M1
// Using 2 pointer
// Faster than 100% (0ms)

class Solution
{
public:
    int maximumSwap(int num)
    {
        string n = to_string(num);
        for (int i = 0; i < n.size(); i++)
        {
            int temp = n[i] - '0' + 1, ind = i;
            for (int j = i + 1; j < n.size(); j++)
            {
                if (n[j] - '0' >= temp)
                {
                    temp = n[j] - '0';
                    ind = j;
                }
            }
            if (ind != i)
            {
                int t = n[i];
                n[i] = n[ind];
                n[ind] = t;
                return stoi(n);
            }
        }
        return num;
    }
};