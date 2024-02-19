//REcursion
class Solution {
public:
    int solve(int index,int buy,vector<int>& prices){

        if(index == prices.size()) return 0;
        
        int profit = 0;

        if(buy){
            
            int Buy = -prices[index] + solve(index+1,0,prices);
            int skip = 0 + solve(index+1,1,prices);
            
            profit = max(Buy,skip);

        }else{

            int sell = prices[index] + solve(index+1,1,prices);
            int skip = 0 + solve(index+1,0,prices);

            profit = max(sell,skip);
        }
        
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        
        return solve(0,1,prices);
    }
};