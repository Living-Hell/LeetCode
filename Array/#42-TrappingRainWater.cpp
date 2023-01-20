//M1
//Using Dp
//Faster than 42.1% (25ms)

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, n = height.size();
        vector<int> left(n,0), right(n,0);

        int mx = INT_MIN;
        for(int i=0; i<n; i++){
            mx = max(height[i], mx);
            left[i] = mx;
        }

        mx = INT_MIN;
        for(int i=n-1; i>0; i--){
            mx = max(height[i], mx);
            right[i] = mx;
        }

        for(int i=0; i<n; i++){
            int water = min(left[i],right[i]) - height[i];
            if(water>0) ans+= water;
        }

        return ans;
    }
};

//M2
//Two pointer approach
//Faster than 99.43% (7ms)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int i = 1, j = n-2;
        int maxl = height[0], maxr = height[n-1];
        int water=0;

        while(i<=j){
            if(maxl < maxr){
                maxl = max(maxl,height[i]);
                water+= maxl-height[i];
                i++;
            }
            else{
                maxr = max(maxr, height[j]);
                water+= maxr - height[j];
                j--;
            }
        }
        return water;
    }
};