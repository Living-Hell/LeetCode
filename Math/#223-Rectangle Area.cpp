// M1
// Using geometry
// Faster than 87.73% (3ms)

class Solution
{
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        int ar1 = (ax2 - ax1) * (ay2 - ay1);
        int ar2 = (bx2 - bx1) * (by2 - by1);
        if (ax2 <= bx1 or bx2 <= ax1 or ay1 >= by2 or ay2 <= by1)
            return ar1 + ar2;
        return ar1 + ar2 - (max(ax1, bx1) - min(ax2, bx2)) * (max(ay1, by1) - min(ay2, by2));
    }
};