//M1
//Using simulation and sets
//Faster than 80.66% (65ms)

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int resX = 0, resY = 0, n = commands.size(), dir = 0, res = 0;
        vector<pair<int, int>> coord = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        set<pair<int, int>> st;
        for (int i = 0; i < obstacles.size(); i++) {
            st.insert({obstacles[i][0], obstacles[i][1]});
        }

        for (int i = 0; i < n; i++) {
            if (commands[i] < 0) {
                dir += commands[i] == -2 ? -1 : 1;
                dir = (dir + 4) % 4;
            } else {
                for (int j = 0; j < commands[i]; j++) {
                    if (st.contains({resX + coord[dir].first,
                                     resY + coord[dir].second}))
                        break;
                    resX += coord[dir].first;
                    resY += coord[dir].second;
                    res = max(res, resX * resX + resY * resY);
                }
            }
        }
        return res;
    }
};
