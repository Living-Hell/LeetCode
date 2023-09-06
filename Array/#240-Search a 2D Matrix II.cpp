// M1
// Through Searching from top right
// Faster than 90.54% (63ms)

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &mat, int target)
    {
        int m = mat.size(), n = mat[0].size();
        int row = 0, col = n - 1;
        while (row < m and col >= 0)
        {
            int val = mat[row][col];
            if (target == val)
                return 1;
            (val < target) ? row++ : col--;
        }
        return 0;
    }
};