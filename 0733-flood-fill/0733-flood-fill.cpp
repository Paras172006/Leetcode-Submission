class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, 
             int originalColor, int color) {
        
        // Boundary check
        if (sr < 0 || sr >= image.size() ||
            sc < 0 || sc >= image[0].size()) {
            return;
        }

        // Only change cells having original color
        if (image[sr][sc] != originalColor) {
            return;
        }

        image[sr][sc] = color;

        dfs(image, sr + 1, sc, originalColor, color);
        dfs(image, sr - 1, sc, originalColor, color);
        dfs(image, sr, sc + 1, originalColor, color);
        dfs(image, sr, sc - 1, originalColor, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, 
                                   int sr, int sc, int color) {
        
        int originalColor = image[sr][sc];

        // If both colors are same, avoid infinite recursion
        if (originalColor == color) {
            return image;
        }

        dfs(image, sr, sc, originalColor, color);

        return image;
    }
};