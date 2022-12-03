//M1
//Using Min Heap
//Faster than 74.33% (53ms) Memory O(n^2)

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue <int, vector<int>, greater<int>> pq;

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                pq.push(matrix[i][j]);
        
        while(--k) pq.pop();
        return pq.top();
        
    }
};

//M2
//Using Binary Search 
//Faster than 57.13% (75ms) Memory O(1)

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int s=matrix[0][0], e=matrix[n-1][n-1], mid;
        int ans;

        while(s<=e){
            mid = s + (e-s)/2;
            int count=0;
            for(int i=0; i<n; i++){
                int pos = upper_bound(matrix[i].begin(), matrix[i].end(),mid) - matrix[i].begin();
                count+= pos;
            }

            if(count<k) s = mid+1;

            else{
                ans = mid;
                e = mid-1;
            }
        }

        return ans;       
        
    }
};