//M1
//Using Stack
//Faster than 83.39%(183ms)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> stl,str;
        vector<int> left(n,0), right(n,0);

        left[0] = -1; stl.push(0);
        for(int i=1; i<n; i++){
            while(!stl.empty() && heights[stl.top()] >= heights[i]) stl.pop();
            if(stl.empty()) left[i] = -1;
            else left[i] = stl.top();
            stl.push(i);
        }

        right[n-1] = n; str.push(n-1);
        for(int i=n-2; i>=0; i--){
            while(!str.empty() && heights[str.top()] >= heights[i]) str.pop();
            if(str.empty()) right[i] = n;
            else right[i] = str.top();
            str.push(i);
        }
        
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            int temp = heights[i] * (right[i] - left[i] - 1);
            ans = max(ans,temp);
        }
        return ans;
    }
};