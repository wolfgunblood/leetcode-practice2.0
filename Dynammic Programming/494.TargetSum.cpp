class Solution {
public:
    int dfs(vector<int>& nums,int index,int total,int& targetSum){

        if(index == nums.size())
            return  (targetSum ==  total) ? 1 : 0;

        return dfs(nums,index+1,total+nums[index],targetSum) + dfs(nums,index+1,total-nums[index],targetSum);

    }

    int findTargetSumWays(vector<int>& nums, int target) {

        return dfs(nums,0,0,target);    
    }
};
//Revisit

class Solution {
private:
    map<pair<int,int>,int> dp;
    int dfs(vector<int>& nums,int index,int total,int& targetSum){

        if(index == nums.size())
            return  (targetSum ==  total) ? 1 : 0;

            if(dp.find({index,total}) != dp.end()) return dp[{index,total}];

        dp[{index,total}] = dfs(nums,index+1,total+nums[index],targetSum) + dfs(nums,index+1,total-nums[index],targetSum);

        return dp[{index,total}];

    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums,0,0,target);    
    }
};