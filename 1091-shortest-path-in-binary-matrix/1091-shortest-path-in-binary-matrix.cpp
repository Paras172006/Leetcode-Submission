
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] == 1 || grid[n-1][m-1] == 1)
            return -1;

        int dx[] = {-1,-1,-1,0,0,1,1,1};
        int dy[] = {-1,0,1,-1,1,-1,0,1};

        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;

        while (!q.empty()) {
            auto [x,y] = q.front();
            q.pop();

            if (x == n-1 && y == m-1)
                return grid[x][y];

            for (int k = 0; k < 8; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;

                if (grid[nx][ny] != 0)
                    continue;

                grid[nx][ny] = grid[x][y] + 1;
                q.push({nx,ny});
            }
        }

        return -1;
    }
};
