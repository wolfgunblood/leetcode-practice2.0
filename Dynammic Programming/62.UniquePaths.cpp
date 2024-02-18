//tabulation 1
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // memset(dp,0,sizeof(dp)); 
        dp[1][1] = 1;
        for(int i =0;i<=m;i++){

            for(int j =0;j<=n;j++){

                // dp[i][j] = dp[i-1][j]+dp[i][j-1];
                int current = dp[i][j];

                if(i+1 <= m) dp[i+1][j] += current;
                if(j+1 <= n) dp[i][j+1] += current;
            }
        }

        return dp[m][n];
    }
};

//tabulation 2

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m,vector<int>(n,1));
        // memset(dp,0,sizeof(dp)); 
        // dp[1][1] = 1;
        for(int i =1;i<m;i++){

            for(int j =1;j<n;j++){

                dp[i][j] = dp[i-1][j]+dp[i][j-1];
                // int current = dp[i][j];

                // if(i+1 <= m) dp[i+1][j] += current;
                // if(j+1 <= n) dp[i][j+1] += current;
            }
        }

        return dp[m-1][n-1];
    }
};

//Recursion
class Solution {
public:
    int uniquePaths(int m, int n) {
        
      if(m == 0 || n == 0) return 0;
      if(m == 1 && n == 1) return 1;

      return uniquePaths(m-1,n) + uniquePaths(m,n-1);
    }
};
//Recursion II
class Solution {
public:
    int uniquePaths(int m, int n,int i = 0,int j =0) {
        
      if(i>=m || j>=n) return 0;
      if(i == m-1 && j == n-1) return 1;

      return uniquePaths(m,n,i+1,j) + uniquePaths(m,n,i,j+1);
    }
};
//memoziation
class Solution {
public:
    int dp[101][101]{}; 
    int uniquePaths(int m, int n,int i = 0,int j =0) {
        
      if(i>=m || j>=n) return 0;
      if(i == m-1 && j == n-1) return 1;
      if(dp[i][j]) return dp[i][j];

      return dp[i][j] = uniquePaths(m,n,i+1,j) + uniquePaths(m,n,i,j+1);
    }
};

//memoziation 2
class Solution {
public:
    int dp[101][101]{}; 
    int uniquePaths(int m, int n) {
        
      if(m == 0 || n == 0) return 0;
      if(m == 1 && n == 1) return 1;
      
      if(dp[m][n]) return dp[m][n];

      return dp[m][n] = uniquePaths(m-1,n) + uniquePaths(m,n-1);
    }
};