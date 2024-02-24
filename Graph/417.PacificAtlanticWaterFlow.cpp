class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        vector<vector<bool>> atlantic(m,vector<bool>(n,false));

        for(int i =0;i<m;i++)
        {
            dfs(heights,pacific,i,0,m,n);
            dfs(heights,atlantic,i,n-1,m,n);
        }

        for(int j =0;j<n;j++){

            dfs(heights,pacific,0,j,m,n);
            dfs(heights,atlantic,m-1,j,m,n);
        }

        vector<vector<int>> result;

        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                // vector<int> curr;
                if(pacific[i][j] && atlantic[i][j]){
                    // curr.push_back(i);
                    // curr.push_back(j);
                    result.push_back({i,j});
                }
                // if(curr.size()>0)
                // result.push_back(curr);
            }
        }

        return result;
       
    }
private: 
    void dfs(vector<vector<int>>& heights,vector<vector<bool>>& vis,int row,int col,int m,int n){

       vis[row][col] = true;

       if(row>0 && !vis[row-1][col] && heights[row-1][col] >= heights[row][col])
       {
           dfs(heights,vis,row-1,col,m,n);
       }
       if(row<m-1 && !vis[row+1][col] && heights[row+1][col] >= heights[row][col])
       {
           dfs(heights,vis,row+1,col,m,n);
       }
       if(col>0 && !vis[row][col-1] && heights[row][col-1] >= heights[row][col])
       {
           dfs(heights,vis,row,col-1,m,n);
       }
       if(col<n-1 && !vis[row][col+1] && heights[row][col+1] >= heights[row][col])
       {
           dfs(heights,vis,row,col+1,m,n);
       }

    }
};