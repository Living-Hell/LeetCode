// M1
// Using binary search
// Faster than 82.89% (3 ms)

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        if (m == 0 or n == 0)
            return 0;

        int low = 0, high = m * n - 1, mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (matrix[mid / n][mid % n] < target)
                low = mid + 1;
            else if (matrix[mid / n][mid % n] > target)
                high = mid - 1;
            else
                return 1;
        }
        return 0;
    }
};