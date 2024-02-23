class Solution {
public:
    int dfs(vector<vector<int>>& grid,int row,int col,int m,int n)
    {
        
        if(row<0 || row>=m || col<0 || col>=n || grid[row][col] == 0) return 0;

        grid[row][col] =0;

        return 1 + dfs(grid,row-1,col,m,n) + dfs(grid,row+1,col,m,n) + dfs(grid,row,col-1,m,n) + dfs(grid,row,col+1,m,n);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> vis(m,vector<int>(n,0));
        int result =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j] == 1 ){
                    result = max(result,dfs(grid,i,j,m,n));
                }
            }
        }

        return result;
    }
};