class Solution {
public:

    int dfs(vector<int>& prices,int index,int buying,vector<vector<int>>& dp){

        if(index >= prices.size()) return 0;

        if(dp[index][buying] != -1) return dp[index][buying];
        int profit =0 ;
        int cooldown = dfs(prices,index+1,buying,dp);
        if(buying){

            int buying = dfs(prices,index+1,0,dp) - prices[index];
            profit = max(buying,cooldown);
        }
        else{
            int selling = dfs(prices,index+2,1,dp) + prices[index];
            profit =  max(selling,cooldown);
        }

        return dp[index][buying] =profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return dfs(prices,0,1,dp);
        
    }
};