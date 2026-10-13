class Solution {
public:
    void solve(vector<vector<char>>& grid,vector<vector<bool>>& vis,int i,int j){
       
        

       if(i<0 || j< 0 || i>=grid.size() || j >= grid[0].size() || grid[i][j] == '0' || vis[i][j]){
            return ;
       } 
       vis[i][j] = true;
       solve(grid,vis,i+1,j);
       solve(grid,vis,i-1,j);
       solve(grid,vis,i,j+1);
       solve(grid,vis,i,j-1);
      
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<bool>> vis(n+1,vector<bool>(m+1,false));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    solve(grid,vis,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};