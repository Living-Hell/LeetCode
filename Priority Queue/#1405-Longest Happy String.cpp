//M1
//Using priority_queue
//Faster than 100% (0ms)

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a) pq.push({a,'a'});
        if(b) pq.push({b,'b'});
        if(c) pq.push({c,'c'});
        string res = "";
        while(pq.size() > 1){
            auto one = pq.top();
            pq.pop();
            auto sec = pq.top();
            pq.pop();
            if(one.first >= 2){
                res += one.second;
                res += one.second;
                one.first -= 2;
            } else {
                res += one.second;
                one.first -= 1;
            }
            if(sec.first >= 2 && sec.first >= one.first){
                res += sec.second;
                res += sec.second;
                sec.first -= 2;
            } else {
                res += sec.second;
                sec.first -= 1;
            }
            if(one.first > 0) pq.push(one);
            if(sec.first > 0) pq.push(sec);
        }
        if(pq.empty()) return res;
        if(pq.top().first >= 2){
            res += pq.top().second;
            res += pq.top().second;
        } else {
            res += pq.top().second;
        }
        return res;
    }
};
