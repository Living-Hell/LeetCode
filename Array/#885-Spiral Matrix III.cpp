//M1
//Using simulation and iteration
//Faster than 42.57% (11ms)

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>> res = {{rStart,cStart}};
        int x = rStart, y = cStart;
        for(int i=0; res.size() < rows*cols; i++){
            int fac = i%4;
            for(int j=0; j<i/2+1; j++){
                x += dir[fac].first, y += dir[fac].second;
                if(x>=0 and x<rows and y>=0 and y<cols)
                    res.push_back({x,y}); 
            }
        }
        return res;        
    }
};
