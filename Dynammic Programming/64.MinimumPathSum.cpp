//Memozization
class Solution {
public:
    int DP(vector<vector<int>>& grid,vector<vector<int>>& dp,int row,int col){

        if(row == 0 && col == 0) return grid[0][0];

        if(row<0 || col <0 ) return INT_MAX;

        if(dp[row][col] != 0) return dp[row][col];

        return dp[row][col] = grid[row][col] + min(DP(grid,dp,row-1,col),DP(grid,dp,row,col-1));
    

    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        return DP(grid,dp,m-1,n-1);
        
    }
};
//Memozization
class Solution {
public:
    int DP(vector<vector<int>>& grid,vector<vector<int>>& dp,int row,int col){

        if(row == 0 && col == 0) return grid[0][0];

        if(row<0 || col <0 ) return INT_MAX;

        if(dp[row][col] != 0) return dp[row][col];

        return dp[row][col] = grid[row][col] + min(DP(grid,dp,row-1,col),DP(grid,dp,row,col-1));
    

    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m,vector<int>(n,0));

        return DP(grid,dp,m-1,n-1);
        
    }
};

//Tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m,vector<int>(n,0));

        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){

                dp[i][j] = grid[i][j];

                if(i == m-1 && j == n-1) continue;

                if(i == m-1) dp[i][j] = dp[i][j+1] + grid[i][j];
                else if(j == n-1) dp[i][j] = dp[i+1][j] + grid[i][j];
                else dp[i][j] = grid[i][j] + min(dp[i+1][j],dp[i][j+1]);
            }
        }

        return dp[0][0];
        
    }
};

//Tabulation


//Tabulation
