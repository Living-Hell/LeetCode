//M1
//Using hashmap and set
//Faster than 26.95% (103ms)

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> st(arr.begin(), arr.end());
        unordered_map<int,int> mp;
        int size = 0;
        vector<int> res;
        for(int i : st){
            mp[i] = ++size;
        }
        for(int &i : arr)
            res.push_back(mp[i]);
        return res;
    }
};
