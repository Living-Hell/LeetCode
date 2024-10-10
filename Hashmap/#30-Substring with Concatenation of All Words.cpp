//M1
//Using hashmaps
//Faster than 89.2% (22 ms)

class Solution {
public:
    vector<int> findSubstring(string& s, vector<string>& words) {
        int n = s.size(), k = words.size(), m = words[0].size(),
            total_size = k * m;
        vector<int> ans;
        unordered_map<string, int> mp;

        if (n < total_size)
            return ans;
        for (string& s : words)
            mp[s]++;

        for (int i = 0; i < m; i++) {
            int left = i, count = 0;
            unordered_map<string, int> umap;

            for (int j = i; j <= n - m; j += m) {
                string temp = s.substr(j, m);
                if (mp.count(temp)) {
                    umap[temp]++;
                    count++;
                    while (umap[temp] > mp[temp]) {
                        string start = s.substr(left, m);
                        umap[start]--;
                        left += m;
                        count--;
                    }
                    if (count == k)
                        ans.push_back(left);
                } else {
                    umap.clear();
                    count = 0;
                    left = j + m;
                }
            }
        }
        return ans;
    }
};
