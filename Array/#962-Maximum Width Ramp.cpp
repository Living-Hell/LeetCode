//M1
//Using sorting and lambda function
//Faster than 41.1% (55 ms)

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++){
            v.push_back({i,nums[i]});
        }
        sort(v.begin(), v.end(), [&](const pair<int,int> &a, const pair<int,int> &b){
            return a.second == b.second ? a.first < b.first : a.second < b.second;
        });
        int minInd = v[0].first, res = 0;
        for(int i=0; i<n; i++){
            int ind = v[i].first;
            res = max(res, ind - minInd);
            minInd = min(minInd,ind);
        } 
        return res;
    }
};
