// M1
// Using bitset function
// Faster than 100% (0ms)

class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        string a = bitset<32>(x).to_string();
        string b = bitset<32>(y).to_string();
        int count = 0;
        for (int i = 0; i < 32; i++)
        {
            count += a[i] != b[i];
        }
        return count;
    }
};