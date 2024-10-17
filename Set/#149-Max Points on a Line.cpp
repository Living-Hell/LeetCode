//M1
//Using sets and tuple
//Faster than 17.9% (96ms)

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 1, n = points.size();
        set<tuple<int, int, int>> st;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int slopeX = points[j][0] - points[i][0];
                int slopeY = points[j][1] - points[i][1];
                int ind = i;
                st.insert({slopeX, slopeY, ind});
            }
        }
        for (auto& e : st) {
            int count = 0, slopeX = get<0>(e), slopeY = get<1>(e),
                ind = get<2>(e);
            for (auto& p : points) {
                if ((p[1] - points[ind][1]) * slopeX == (p[0] - points[ind][0]) * slopeY)
                    count++;
            }
            res = max(res, count);
        }
        return res;
    }
};
