class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& imag, int sr, int sc, int color) {
        vector<vector<int>> image = imag;
        int ocolor = image[sr][sc];
        if (ocolor == color) return image;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc] = color;
       int dx[] = {1,-1,0,0};
       int dy[] = {0,0,-1,1};
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
           for(int i = 0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx < 0 || ny < 0 || nx >= image.size() || ny >= image[0].size()){
                continue;
            }
            if(image[nx][ny] != ocolor){
                continue;
            }
            image[nx][ny] = color;
            q.push({nx,ny});
           }
        }

           return image;
        }
};