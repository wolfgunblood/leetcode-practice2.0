//Memoziation
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    
    if(s1.length() + s2.length() != s3.length()) return false;
     return dfs(s1,s2,s3,0,0);

    }
private:
    map<pair<int,int>,bool> dp;

    bool dfs(string s1,string s2,string s3,int i,int j){

        if(i == s1.length() && j == s2.length()) return true;

        if(dp.find({i,j}) != dp.end()) return dp[{i,j}];

        if(i < s1.length() && s1[i] == s3[i+j] && dfs(s1,s2,s3,i+1,j)) return true;
        if(j < s2.length() && s2[j] == s3[i+j] && dfs(s1,s2,s3,i,j+1)) return true;

        dp[{i,j}] =false;
        return dp[{i,j}];
    }
};
//Dp solution
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    
    if(s1.length() + s2.length() != s3.length()) return false;
    int m = s1.length();
    int n = s2.length();

    vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
    dp[m][n] =true;

    for(int i= m;i>=0;--i){
        for(int j = n;j>=0;--j){

            if(i<m && s1[i] == s3[i+j] && dp[i+1][j]) dp[i][j] =true;
            if(j<n && s2[j] == s3[i+j] && dp[i][j+1]) dp[i][j] =true;
        }
    }

    return dp[0][0];

    }
private:
    map<pair<int,int>,bool> dp;

    bool dfs(string s1,string s2,string s3,int i,int j){

        if(i == s1.length() && j == s2.length()) return true;

        if(dp.find({i,j}) != dp.end()) return dp[{i,j}];

        if(i < s1.length() && s1[i] == s3[i+j] && dfs(s1,s2,s3,i+1,j)) return true;
        if(j < s2.length() && s2[j] == s3[i+j] && dfs(s1,s2,s3,i,j+1)) return true;

        dp[{i,j}] =false;
        return dp[{i,j}];
    }
};