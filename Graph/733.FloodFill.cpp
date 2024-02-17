class Solution {
public:
    void dfs(vector<vector<int>>& image,int newColor,int color,int sr,int sc){

        if(sr<0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != newColor) return;

  
        image[sr][sc] = color;
       
        dfs(image,newColor,color,sr-1,sc);
        dfs(image,newColor,color,sr+1,sc);
        dfs(image,newColor,color,sr,sc-1);
        dfs(image,newColor,color,sr,sc+1);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size();

        if(image[sr][sc] == color) return image;

        dfs(image,image[sr][sc],color,sr,sc);
        return image;
    }
};

//Flood Fill

class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if (color != newColor) {
            dfs(image, sr, sc, color, newColor);
        }
        return image;
    }
    public void dfs(int[][] image, int r, int c, int color, int newColor) {
        if (image[r][c] == color) {
            image[r][c] = newColor;
            if (r >= 1) {
                dfs(image, r - 1, c, color, newColor);
            }
            if (c >= 1) {
                dfs(image, r, c - 1, color, newColor);
            }
            if (r + 1 < image.length) {
                dfs(image, r + 1, c, color, newColor);
            }
            if (c + 1 < image[0].length) {
                dfs(image, r, c + 1, color, newColor);
            }
        }
    }
}