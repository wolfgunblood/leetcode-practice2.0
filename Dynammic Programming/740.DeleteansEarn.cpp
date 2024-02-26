class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        n= nums.size();
        sort(nums.begin(),nums.end());
        memo.resize(n+1,-1);
        for(auto num : nums) mp[num]++;

        return dp(nums,0,nums[n-1]);
    }
private:
    unordered_map<int,int> mp;
    int n;
    vector<int> memo;
    int dp(vector<int>& nums,int i,int last){
        
        if(nums[i] == last) return nums[i]*mp[nums[i]];

        if(i>=n) return 0;

        if(memo[i] != -1) return memo[i];

        int ind1 = upper_bound(nums.begin(),nums.end(),nums[i]+1) -nums.begin();
        int ind2 = upper_bound(nums.begin(),nums.end(),nums[i]) -nums.begin();

        int pick = nums[i]*mp[nums[i]] + dp(nums,ind1,last); 
        int notPick = dp(nums,ind2,last); 
        memo[i] = max(pick,notPick);
        return memo[i];
    }
};