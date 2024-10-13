//M1
//Using sliding window and sorting
//Faster than 99.47% (27ms)

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> v;
        int k = nums.size();
        for (int i = 0; i < k; i++) {
            for (int& num : nums[i])
                v.push_back({num, i});
        }
        vector<int> vis(k, 0);
        int st = 0, end = 0, n = v.size(), resSt = 0, resEnd = n - 1, count = 0;
        sort(v.begin(), v.end());

        while (end < n) {
            if (vis[v[end].second] == 0)
                count++;
            vis[v[end].second]++;
            while (count == k) {
                if (v[resEnd].first - v[resSt].first >
                    v[end].first - v[st].first) {
                    resSt = st;
                    resEnd = end;
                }
                vis[v[st].second]--;
                if (vis[v[st].second] == 0)
                    count--;
                st++;
            }
            end++;
        }
        return {v[resSt].first, v[resEnd].first};
    }
};

//M2
//Using sliding window and sorting
//Faster than 5.01% (233ms)

class Solution {
public:
    bool check(vector<int> &vis){
        for(int &i:vis){
            if(i == 0)
                return false;
        }
        return true;
    }
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>> v;
        int k = nums.size();
        for(int i=0; i<k; i++){
            for(int &num : nums[i])
                v.push_back({num,i});
        }
        vector<int> vis(k,0);
        int st = 0, end = 0, n = v.size(), resSt = 0, resEnd = n-1;
        sort(v.begin(), v.end());

        while(end < n){
            vis[v[end].second]++;
            while(check(vis)){
                if(v[resEnd].first - v[resSt].first > v[end].first - v[st].first){
                    resSt = st;
                    resEnd = end;
                }
                vis[v[st++].second]--;
            }
            end++;
        }
        return {v[resSt].first,v[resEnd].first};
    }
};

