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

//M2
//Using 2 priority queues (min heap) and tuple
//Faster than 95.56 (124ms)

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<tuple<int, int, int>> v;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        priority_queue<int,vector<int>,greater<int>> avlChairs;

        int i = 0, n = times.size(), allotted = 0;
        for (int i = 0; i < n; i++) {
            v.push_back({times[i][0], times[i][1], i});
        }
        sort(v.begin(), v.end());
        while (i < n) {
            int arriveTime = get<0>(v[i]);
            int leaveTime = get<1>(v[i]);
            int frnd = get<2>(v[i]);

            while(!pq.empty() and get<0>(pq.top()) <= get<0>(v[i])) {
                int freedChair = get<1>(pq.top());
                pq.pop();
                avlChairs.push(freedChair);
            }
            int chairToGive;
            if(!avlChairs.empty()){
                chairToGive = avlChairs.top();
                avlChairs.pop();
            } else {
                chairToGive = allotted++;
            }

            if(frnd == targetFriend)
                return chairToGive;
            
            pq.push({leaveTime,chairToGive,frnd});
            i++;
        }
        return -1;
    }
};
