
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    q.push({i,j});
                } else {
                    mat[i][j] = -1;
                }
            }
        }

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || ny < 0 ||
                   nx >= n || ny >= m) {
                    continue;
                }

                if(mat[nx][ny] != -1) {
                    continue;
                }

                mat[nx][ny] = mat[x][y] + 1;
                q.push({nx,ny});
            }
        }

        return mat;
    }
};
