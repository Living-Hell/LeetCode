//M1
//Sorting and Greedy Approach
//Faster than 87.16% (85ms)
class Solution {
public:
    static bool lambda(const vector<int>& a, const vector<int>& b){
        return(a[1]<b[1]);
    }
    int findLongestChain(vector<vector<int>>& p) {

        int n = p.size();
        sort(p.begin(), p.end(), lambda);
        int ans=0, curr_as=INT_MIN;
        
        for(int i=0; i<n; i++){
            if(curr_as<p[i][0]){
                ans++;
                curr_as = p[i][1];
            }
        }
        return ans;
    }
};