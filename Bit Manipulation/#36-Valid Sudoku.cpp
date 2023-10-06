// M1
// Using bit manipulation
// Faster than 28.11% (23ms)

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<int> rows(9, 0), cols(9, 0), blocks(9, 0);
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                int curr = board[i][j] - '0';
                int temp = 1 << curr;
                if ((rows[i] & temp) or (cols[j] & temp) or (blocks[(i / 3) * 3 + j / 3] & temp))
                    return 0;
                rows[i] |= temp;
                cols[j] |= temp;
                blocks[(i / 3) * 3 + j / 3] |= temp;
            }
        }
        return 1;
    }
};