class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fr = 0;
         queue<pair<int,int>> q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2){
                   q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    fr++;
                }
            }
        }
        if(fr == 0){
            return 0;
        }
        int cnt = 0;
        // if(q.empty()){
        //     return 0;
        // }
        while(!q.empty() && fr> 0){
            
            int k = q.size();
            for( int i = 0;i<k;i++){
                auto [x,y] = q.front();
                q.pop();
              int dx[] = {1,-1,0,0};
              int dy[] = {0,0,-1,1};
              for(int j = 0;j<4;j++){
                int nx = x+dx[j];
                int ny = y+dy[j];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m ){
                    continue;
                }
                if(grid[nx][ny] == 2 || grid[nx][ny] == 0){
                    continue;
                }
                grid[nx][ny] = 2;
                fr--;
                q.push({nx,ny});
              }

            }
            
             cnt++;
        }

        return fr == 0 ? cnt : -1;
    }
};