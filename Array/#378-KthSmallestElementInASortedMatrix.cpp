//M1
//Using Min Heap
//Faster than 74.33% (53ms)

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