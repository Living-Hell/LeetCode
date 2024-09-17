//M1
//Using hashmap
//Faster than 51.8% (2ms)

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        string temp = "";
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == ' ') {
                mp[temp]++;
                temp = "";
            } else {
                temp.push_back(s1[i]);
            }
        }
        if (temp.size()) {
            mp[temp]++;
            temp = "";
        }
        for (int i = 0; i < s2.size(); i++) {
            if (s2[i] == ' ') {
                mp[temp]++;
                temp = "";
            } else {
                temp.push_back(s2[i]);
            }
        }
        if (temp.size()) {
            mp[temp]++;
            temp = "";
        }
        vector<string> res;
        for (auto& m : mp) {
            if (m.second == 1)
                res.push_back(m.first);
        }
        return res;
    }
};
