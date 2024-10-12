//M1
//Using priority queue and sorting
//Faster than 56.98% (291 ms)

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = intervals.size(), res = 1;
        for(int i=0; i<n; i++){
            while(!pq.empty() and pq.top() < intervals[i][0]){
                pq.pop();
            }
            if(pq.empty() or pq.top() >= intervals[i][0]){
                pq.push(intervals[i][1]);
            }
            res = max(res,(int)pq.size());
        }
        return res;
    }
};
