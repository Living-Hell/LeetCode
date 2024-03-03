// M1
// Using maths
// Faster than 100% (0ms)

class Solution
{
public:
    int bulbSwitch(int n)
    {
        // All the numbers which are perfect squared have even number of factors excluding 1
        // Eg: 6 = 2,3,6,1 (2*3)(6*1)
        // While perfect square will have only odd numbers of factors since one of the factor, sq root, comes twice
        // Eg: 16 = 1,2,4,8,16 (1*16)(2*8)(4*4)
        // So, bulbs with indices as perfect square will go add number of toggles and will be left turned on at the end
        return sqrt(n);
    }
};