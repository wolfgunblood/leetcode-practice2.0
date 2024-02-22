class Solution {
public:
    map<pair<int,int>,int> dp;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        int LIP = -1; 
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++){

                LIP = max(LIP,dfs(matrix,i,j,-1));
            }
        }

        return LIP;
    }
private:
    int dfs(vector<vector<int>>& matrix,int i,int j,int prevValues){

        if(i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size() || matrix[i][j]<=prevValues)
            return 0;
        
        if(dp[{i,j}]) return dp[{i,j}];

        int res =1;
        res = max(res,1+dfs(matrix,i-1,j,matrix[i][j]));
        res = max(res,1+dfs(matrix,i+1,j,matrix[i][j]));
        res = max(res,1+dfs(matrix,i,j-1,matrix[i][j]));
        res = max(res,1+dfs(matrix,i,j+1,matrix[i][j]));

        return dp[{i,j}] = res;
    }
};