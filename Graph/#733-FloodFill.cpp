//M1
//Using BFS and Queue
//Faster than 45.49%(14ms)

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,0));
        queue<pair<int,int>> q;
        vector<pair<int,int>> moves = {{0,-1},{0,1},{-1,0},{1,0}};

        q.push(make_pair(sr,sc));
        visited[sr][sc]=1;

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            for(auto mv:moves){
                int x = top.first + mv.first, y = top.second + mv.second;
                if(x>=0 && x<m && y>=0 && y<n && 
                  !visited[x][y] && image[x][y] == image[sr][sc]){                    
                    visited[x][y]=1;
                    image[x][y]=color;
                    q.push(make_pair(x,y));
                }                
            }
        }
        image[sr][sc]=color;
        return image;
        
    }
};