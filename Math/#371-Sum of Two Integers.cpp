// M1
// Using Maths
// Faster than 100% (0ms)

class Solution
{
public:
    int getSum(int a, int b)
    {
        return log2(pow(2, a) * pow(2, b));
    }
};

// M2
// Using bitwise operators
// Faster than 55.2% (2ms)

class Solution
{
public:
    int getSum(int a, int b)
    {
        while (b != 0)
        {
            unsigned int carry = a & b;
            a ^= b;
            b = carry << 1;
        }
        return a;
    }
};