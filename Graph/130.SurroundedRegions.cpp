class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0;i<m;i++){
            dfs(board,i,0,m,n);
            dfs(board,i,n-1,m,n);
        }
        for(int j = 0;j<n;j++){
            dfs(board,0,j,m,n);
            dfs(board,m-1,j,m,n);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(board[i][j] == 'O')
                board[i][j] = 'X';
                if(board[i][j] == 'E')
                board[i][j] ='O';
            }
        }
    }
private:
    void dfs(vector<vector<char>>& board,int row,int col,int m,int n){

        if(row < 0 || row >= m || col < 0 || col >= n || board[row][col] != 'O') return ;

        board[row][col] = 'E';
        dfs(board,row-1,col,m,n);
        dfs(board,row+1,col,m,n);
        dfs(board,row,col-1,m,n);
        dfs(board,row,col+1,m,n);
    }
};