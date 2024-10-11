//M1
//Using priority queue
//Faster than 98.97% (118ms)

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<tuple<int, int, int>> v;
        priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> pq;
        int n = times.size();
        vector<int> availableChairs;
        int allotted = 0;
        
        for (int i = 0; i < n; i++) {
            v.push_back({times[i][0], times[i][1], i});
        }
        
        sort(v.begin(), v.end());
        
        for (int i = 0; i < n; i++) {
            int arrival = get<0>(v[i]);
            int leave = get<1>(v[i]);
            int friendIndex = get<2>(v[i]);
            
            while (!pq.empty() && get<0>(pq.top()) <= arrival) {
                availableChairs.push_back(get<1>(pq.top()));
                pq.pop();
            }
            
            int chair;
            if (!availableChairs.empty()) {
                chair = *min_element(availableChairs.begin(), availableChairs.end());
                availableChairs.erase(min_element(availableChairs.begin(), availableChairs.end()));
            } else {
                chair = allotted++;
            }
            
            if (friendIndex == targetFriend) {
                return chair;
            }
            
            pq.push({leave, chair});
        }
        
        return -1;
    }
};
