//M1
//Using priority queue
//Faster than 57.86% (195ms)

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long res = 0;
        priority_queue<int> pq(nums.begin(), nums.end());
        while(k--){
            int top = pq.top();
            pq.pop();
            res += top;
            pq.push(ceil(top/3.0));
        }
        return res;
    }
};
