//M1
//Using vector
//Faster than 93.14% (20ms)

class CustomStack {
public:
    vector<int> v;
    int top, size;
    CustomStack(int maxSize) {
        v.resize(maxSize, -1);
        size = maxSize;
        top = 0;
    }
    
    void push(int x) {
        if(top == size)
            return;
        v[top] = x;
        top = top+1;
    }
    
    int pop() {
        if(top == 0)
            return -1;
        int topEl = v[--top];
        return topEl;
    }
    
    void increment(int k, int val) {
        for(int i=0; i<min(size,k); i++){
            if(v[i] == -1) return;
            v[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
