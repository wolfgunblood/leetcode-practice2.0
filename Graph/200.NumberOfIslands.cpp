class Solution {
public:

    void dfs(vector<vector<char>>& grid,int i,int j,int n,int m){

        if( i<0 || i>=n || j<0 || j>=m || grid[i][j] != '1') return ;

        grid[i][j] = '9';
        dfs(grid,i-1,j,n,m);
        dfs(grid,i+1,j,n,m);
        dfs(grid,i,j-1,n,m);
        dfs(grid,i,j+1,n,m);
        // grid[i][j] = '1';
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int island = 0;

        for(int i = 0; i<n ; i++){
            for(int j = 0; j<m ;j++){

                if(grid[i][j] == '1'){
                    
                    island++;
                    dfs(grid,i,j,n,m);
                }
            }
        }

        return island;

    }
};

//More Solution

int delRow[] = {1,-1,0,0};
int delCol[] = {0,0,-1,1};


class Solution {
public:

    void dfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int row,int col,int n,int m){

        if( row<0 || row>=n || col<0 || col>=m || vis[row][col] == 1) return ;

        vis[row][col] = 1;

        for(int i =0;i<4;i++)
        {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == '1' && vis[nRow][nCol] == 0)
            // if(vis[nRow][nCol] == 0 && grid[nRow][nCol] == '1')
            dfs(grid,vis,nRow,nCol,n,m);
        }

       
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int island = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i = 0; i<n ; i++){
            for(int j = 0; j<m ;j++){

                if(grid[i][j] == '1' && vis[i][j] == 0){
                    island++;
                    dfs(grid,vis,i,j,n,m);
                }
            }
        }

        return island;

    }
};

//Modified and more detailed explained

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));

        int island = 0;

        for(int i=0;i<m;i++){
            for(int j =0;j<n;j++){

                if(grid[i][j] == '1' && !vis[i][j])
                {
                    dfs(grid,vis,i,j);
                    island++;
                }
            }
        }

        return island;
    }
private:
    void dfs(vector<vector<char>>& grid,vector<vector<bool>>& vis,int row, int col){

        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || vis[row][col] || grid[row][col] != '1') return;

        vis[row][col] = true;

        int delRow[] = {-1,1,0,0};
        int delCol[] = {0,0,-1,1};

        for(int i =0;i<4;i++)
        {
            int dx = row + delRow[i]; 
            int dy = col + delCol[i];

            // if(dx>=0 && dx<grid.size() && dy>=0 && dy<grid[0].size() && !vis[dx][dy])
                dfs(grid,vis,dx,dy);
        }
       
    //    if(row-1>=0 && row-1<grid.size() && col>=0 && col<grid[0].size() && !vis[row-1][col])
    //    dfs(grid,vis,row-1,col);
    //    if(row+1>=0 && row+1<grid.size() && col>=0 && col<grid[0].size() && !vis[row+1][col])
    //    dfs(grid,vis,row+1,col);
    //    if(row>=0 && row<grid.size() && col-1>=0 && col-1<grid[0].size() && !vis[row][col-1])
    //    dfs(grid,vis,row,col-1);
    //    if(row>=0 && row<grid.size() && col+1>=0 && col+1<grid[0].size() && !vis[row][col+1])
    //    dfs(grid,vis,row,col+1);
    }
};