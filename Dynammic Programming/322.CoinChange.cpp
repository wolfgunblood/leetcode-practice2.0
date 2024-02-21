//Recursion

class Solution {
public:
    int dp[12 +1][10000 + 1];

    int DP(vector<int>& coins,int index,int amount){

        if(index >= coins.size() || amount <= 0)
        {
            return (amount == 0) ? 0 : INT_MAX-1;
        }
        int res = -1;

        if(dp[index][amount] != -1) return dp[index][amount];

        if(coins[index] > amount){

            int doNotTakeCoin = 0 + DP(coins,index + 1,amount - 0);
            dp[index][amount] = res = doNotTakeCoin;
        }else{
            int takeCoin = 1 + DP(coins,index+0,amount - coins[index]);
            int doNotTakeCoin = 0 + DP(coins,index+1,amount - 0);

            dp[index][amount] = res = min(takeCoin,doNotTakeCoin);
        }
        return dp[index][amount];
        
    }

    int coinChange(vector<int>& coins, int amount) {
        
        memset(dp,-1,sizeof(dp));
        int res = DP(coins,0,amount);

        return (res == INT_MAX-1) ? -1 : res ;
    }
};

//DP 

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int dp[amount +1];
        dp[0] = 0;

        for(int i =1;i<=amount;i++){
            dp[i] = 1e9;

            for(auto c : coins){

                if(i - c >=0){

                    dp[i] = min(dp[i],dp[i-c]+1);
                }
            }
        }

        return dp[amount] == 1e9 ? -1 : dp[amount];
       
    }
};