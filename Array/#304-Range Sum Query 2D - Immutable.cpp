// M1
// Using precomputation
// Faster than 72% (287 ms)

class NumMatrix
{
public:
    vector<vector<int>> mat;
    NumMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        mat.resize(m, vector<int>(n));
        mat[0][0] = matrix[0][0];
        for (int i = 1; i < n; i++)
            mat[0][i] = mat[0][i - 1] + matrix[0][i];
        for (int i = 1; i < m; i++)
            mat[i][0] = mat[i - 1][0] + matrix[i][0];

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                mat[i][j] = mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int ans = mat[row2][col2];
        int col = 0, row = 0, add = 0;
        if (row1 > 0)
        {
            row = mat[row1 - 1][col2];
        }
        if (col1 > 0)
        {
            col = mat[row2][col1 - 1];
        }
        if (col1 > 0 and row1 > 0)
        {
            add = mat[row1 - 1][col1 - 1];
        }
        return ans - row - col + add;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */