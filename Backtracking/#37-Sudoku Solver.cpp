// M1
// Using backtracking
// Faster than 84.8% (18ms)

class Solution
{
public:
    bool safe(vector<vector<char>> &board, int i, int j, char k)
    {
        for (int t = 0; t < 9; t++)
        {
            if (board[i][t] == k)
                return 0;
            if (board[t][j] == k)
                return 0;
            if (board[(i / 3) * 3 + t / 3][(j / 3) * 3 + t % 3] == k)
                return 0;
        }
        return 1;
    }
    bool solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                    continue;
                for (int k = '1'; k <= '9'; k++)
                {
                    if (safe(board, i, j, k))
                    {
                        board[i][j] = k;
                        if (solve(board))
                            return 1;
                        board[i][j] = '.';
                    }
                }
                return 0;
            }
        }
        return 1;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};