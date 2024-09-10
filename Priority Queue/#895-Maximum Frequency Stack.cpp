//M1
//Using priority queue and hashmap
//Faster than 55.23% (176 ms)

class FreqStack {
public:
    priority_queue<tuple<int,int,int>> pq;
    unordered_map<int,int> freq;
    int time;
    FreqStack() {
        time = 0;
    }
    
    void push(int val) {
        time += 1;
        freq[val] += 1;
        pq.push({freq[val],time,val});
    }
    
    int pop() {
        auto [f,t,v] = pq.top();
        pq.pop();
        freq[v]--;
        return v;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
