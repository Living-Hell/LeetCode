// M1
// Using DFS
// Faster than 95.17% (3ms)

class Solution
{
public:
    int countBattleships(vector<vector<char>> &board)
    {
        int m = board.size(), n = board[0].size();
        queue<pair<int, int>> q;
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'X')
                {
                    cout << i << " " << j << endl;
                    int temp = 0;
                    board[i][j] = '.';
                    int x = i, y = j;
                    if (x + 1 < m and board[x + 1][y] == 'X')
                    {
                        temp++;
                        while (x + 1 < m and board[x + 1][y] == 'X')
                        {
                            board[x + 1][y] = '.';
                            x++;
                        }
                    }
                    x = i, y = j;
                    if (y + 1 < n and board[x][y + 1] == 'X')
                    {
                        temp++;
                        while (y + 1 < n and board[x][y + 1] == 'X')
                        {
                            board[x][y + 1] = '.';
                            y++;
                        }
                    }
                    ans += temp == 0 ? 1 : temp;
                }
            }
        }
        return ans;
    }
};
