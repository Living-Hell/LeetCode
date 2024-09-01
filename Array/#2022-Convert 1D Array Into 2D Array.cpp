//M1
//Using Iteration and intuition
//Faster than 65.77% (80ms)

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> res;
        if (original.size() != m * n)
            return res;

        vector<int> temp;
        for (int i = 0; i < original.size(); i++) {
            if (i % n == 0) {
                if (i > 0)
                    res.push_back(temp);
                temp = {};
            }
            temp.push_back(original[i]);
        }
        res.push_back(temp);
        return res;
    }
};
