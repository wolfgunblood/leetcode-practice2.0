class Solution {
public:
  bool dfs(vector<vector<char>>& board,string word,int index,int i,int j,int n,int m){

        if(i<0 || i>=n || j<0 || j>=m || board[i][j] != word[index]) return false;

        if(index == word.size() - 1 ) return true;

        // Mode visited
        board[i][j] = '#';

        if(dfs(board,word,index+1,i-1,j,n,m) || dfs(board,word,index+1,i+1,j,n,m) ||
            dfs(board,word,index+1,i,j-1,n,m) || dfs(board,word,index+1,i,j+1,n,m)){
                return true;
        }

        board[i][j] = word[index];
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i<n ; i++){
            for(int j = 0; j<m ; j++){

                if(board[i][j] == word[0]){
                    if(dfs(board,word,0,i,j,n,m)){
                        return true;
                    }
                }
            }
        }

        return false;
  
    }
};