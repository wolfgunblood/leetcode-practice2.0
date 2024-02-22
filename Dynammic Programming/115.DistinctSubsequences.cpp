class Solution {
public:
    map<pair<int,int>,int> dp;
    int numDistinct(string s, string t) {
        
        int m = s.length();
        int n = t.length(); 
        return DFS(s,t,0,0);
        
    }
private : 
    //Pass by refernce affects time
    int DFS(string& s,string& t,int i,int j){

        //Right Order
        if(j == t.length()) return 1;
        if(i == s.length()) return 0;

        //Order Matters -- Wrong Order
        // if(i == s.length()) return 0;
        // if(j == t.length()) return 1;

        if(dp.find({i,j}) != dp.end()) return dp[{i,j}]; 

        if(s[i] == t[j]){
            dp[{i,j}] = DFS(s,t,i+1,j) + DFS(s,t,i+1,j+1);
        }else{
            dp[{i,j}] = DFS(s,t,i+1,j);
        }

        return dp[{i,j}];
    }
};