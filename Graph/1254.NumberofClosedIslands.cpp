class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();

        vector<vector<bool>> visit(m,vector<bool>(n,false));

        int closedIsland = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j] == 0 && !visit[i][j] && dfs(grid,visit,i,j)){
                    
                    closedIsland++;

                }

            }
        }

        return closedIsland;
    }
private:
    bool dfs(vector<vector<int>>& grid,vector<vector<bool>>& visit,int row,int col){

        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size())
        return false;

        if(grid[row][col] == 1 || visit[row][col]) return true;

        visit[row][col] = true;
        int dirx[] = {-1,1,0,0};
        int diry[] = {0,0,-1,1};
        bool isClosed = true;
        for(int i =0;i<4;i++){

            int dx = row + dirx[i];
            int dy = col + diry[i];

            if(!dfs(grid,visit,dx,dy))
            {
                isClosed = false;
            }
        }

        return isClosed;

    }
};