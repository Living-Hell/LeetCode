// M1
// Using BFS
// Faster than 63.11% (11ms)

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        int m = board.size(), n = board[0].size();
        bool vis[m][n];
        memset(vis, 0, sizeof(vis));
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O')
            {
                q.push({i, 0});
                board[i][0] = '#';
            }
            if (board[i][n - 1] == 'O')
            {
                q.push({i, n - 1});
                board[i][n - 1] = '#';
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (board[0][i] == 'O')
            {
                q.push({0, i});
                board[0][i] = '#';
            }
            if (board[m - 1][i] == 'O')
            {
                q.push({m - 1, i});
                board[m - 1][i] = '#';
            }
        }

        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            int x = top.first, y = top.second;
            for (auto p : dir)
            {
                int i = x + p.first, j = y + p.second;
                if (i >= 0 and i < m and j >= 0 and j < n and board[i][j] == 'O')
                {
                    q.push({i, j});
                    board[i][j] = '#';
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '#')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }
};