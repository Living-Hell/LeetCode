//M1
//Using BFS
//Faster than 22.12% (27ms)

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> ans = {{1, 2, 3}, {4, 5, 0}};
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        set<vector<vector<int>>> vis;
        deque<tuple<int, int, int, vector<vector<int>>>> dq;
        vis.insert(board);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) {
                    dq.push_back({i, j, 0, board});
                    break;
                }
            }
        }
        while (!dq.empty()) {
            auto [x, y, count, tempBoard] = dq.front();
            dq.pop_front();
            if (tempBoard == ans)
                return count;
            for (auto& d : dir) {
                int i = x + d.first, j = y + d.second;
                if (i >= 0 and i < 2 and j >= 0 and j < 3) {
                    vector<vector<int>> temp = tempBoard;
                    swap(temp[x][y], temp[i][j]);
                    if (!vis.count(temp)) {
                        dq.push_back({i, j, count + 1, temp});
                        vis.insert(temp);
                    }
                }
            }
        }
        return -1;
    }
};
