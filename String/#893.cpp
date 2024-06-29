// Using Sets
// Faster than 93.39% (3ms)

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        int n = words.size();
        unordered_set<string> v;

        for (int i = 0; i < n; i++) {
            int m = words[i].size();
            string odd = "", even = "";
            for (int j = 0; j < m; j++) {
                if (j % 2 == 1)
                    odd.push_back(words[i][j]);
                else
                    even.push_back(words[i][j]);
            }
            sort(odd.begin(), odd.end());
            sort(even.begin(), even.end());
            odd = odd + " : " + even;
            cout << odd << " : " << endl;
            v.insert(odd);
        }
        return v.size();
    }
};