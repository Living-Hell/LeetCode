// M1
// Using sorting
// Faster than 97.38% (3 ms)

class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        int sz = max(m, n);

        vector<vector<int>> v(2 * sz, vector<int>());

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                v[i - j + sz].push_back(mat[i][j]);
            }
        }

        for (int i = 0; i < 2 * sz; i++)
        {
            sort(v[i].begin(), v[i].end(), greater<int>());
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mat[i][j] = v[i - j + sz].back();
                v[i - j + sz].pop_back();
            }
        }

        return mat;
    }
};