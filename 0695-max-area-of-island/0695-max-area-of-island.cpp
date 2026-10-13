class Solution {
public:

 int solve(vector<vector<int>>& grid,
               vector<vector<bool>>& vis,
               int i, int j) {

        int n = grid.size();
        int m = grid[0].size();

        // Boundary check + water + already visited
        if (i < 0 || j < 0 || i >= n || j >= m ||
            grid[i][j] != 1 || vis[i][j]) {
            return 0;
        }

        vis[i][j] = true;
       
       return 1 +  solve(grid, vis, i + 1, j)+ solve(grid, vis, i - 1, j)+ solve(grid, vis, i, j + 1)+ solve(grid, vis, i, j - 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
         if (grid.empty() || grid[0].empty()) return 0;

        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int val = solve(grid, vis, i, j);
                    maxi = max(maxi,val);
                    
                }
            }
        }

        return maxi;
    }
};