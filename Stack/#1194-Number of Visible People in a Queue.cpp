//M1
//Using monotonic stack to store height in sorted order
//Faster than 54.8% (118ms)

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> res(n,0);

        st.push(heights[n-1]);

        for(int i = n-2; i>=0; i--){
            while(st.size() and st.top() < heights[i]){
                res[i]++;
                st.pop();
            }
            if(st.size()) res[i]++;
            st.push(heights[i]);
        }
        return res;
    }
};
