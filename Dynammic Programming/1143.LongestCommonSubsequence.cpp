class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int m = text1.length();
        int n = text2.length();
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(int i=m-1;i>=0;i--){

            for(int j =n-1;j>=0;j--){

                if(text1[i] == text2[j]) dp[i][j] = 1+ dp[i+1][j+1];
                else
                dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
            }
        }

        return dp[0][0];
    }
};
//Another Approach
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int m = text1.length();
        int n = text2.length();
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(int i=1;i<=m;i++){

            for(int j =1;j<=n;j++){

                if(text1[i-1] == text2[j-1]) dp[i][j] = 1+ dp[i-1][j-1];
                else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }

        return dp[m][n];
    }
};

//Recursion solution

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        return lcshelper(text1,text2,text1.size(),text2.size());
    }

    int lcshelper(string text1,string text2,int m,int n){

        if(m == 0 || n == 0) return 0;

        if(text1[m-1] == text2[n-1]) return 1+lcshelper(text1,text2,m-1,n-1);

        return max(lcshelper(text1,text2,m,n-1) , lcshelper(text1,text2,m-1,n)); 

    }
};
//Memozation
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

        return lcshelper(text1,text2,dp,m,n);
    }

    // int lcshelper(string text1,string text2,vector<vector<int>>& dp,int m,int n){ // Pass by refernce error
    int lcshelper(string& text1,string& text2,vector<vector<int>>& dp,int m,int n){

        if(m == 0 || n == 0) return 0;

        if(dp[m][n] != -1) return dp[m][n];

        if(text1[m-1] == text2[n-1]) dp[m][n] = 1+lcshelper(text1,text2,dp,m-1,n-1);
        else dp[m][n] =max(lcshelper(text1,text2,dp,m,n-1) , lcshelper(text1,text2,dp,m-1,n)); 

        return dp[m][n];
    }
};