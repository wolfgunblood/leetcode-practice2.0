class Solution {
public:
    int minDistance(string word1, string word2) {
        
        if(word1.empty() && word2.empty()) return 0;
        if(word1.empty() || word2.empty()) return 1;

        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1));

        for(int i =m;i>=0;i--){
            dp[i][n] = m-i;
        }

        for(int j =n;j>=0;j--){
            dp[m][j] = n-j;
        }

        for(int i =m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(word1[i] == word2[j]){
                    dp[i][j] = dp[i+1][j+1];
                }else{
                    dp[i][j] = 1 + min(min(dp[i+1][j],dp[i][j+1]),dp[i+1][j+1]);
                }
            }
        }

        return dp[0][0];
    }
};