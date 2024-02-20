//Bottom Down
class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size()-1;
        vector<int> memo(n+1,-1);
        return DP(nums,memo,n);
    }

    int DP(vector<int>& nums,vector<int>& memo,int i){

        if(i<0) return 0;
        if(memo[i] >=0 ) return memo[i];

        memo[i] = max(DP(nums,memo,i-2)+nums[i],DP(nums,memo,i-1));
        // memo[i] = result; 
        return memo[i];
    }
};

//Bottom UP
class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size()-1;
        vector<int> memo(n+1,-1);
        return DP(nums,memo,0);
    }

    int DP(vector<int>& nums,vector<int>& memo,int i){

        if(i>nums.size()-1) return 0;
        if(memo[i] >=0 ) return memo[i];

        memo[i] = max(DP(nums,memo,i+2)+nums[i],DP(nums,memo,i+1));
        // memo[i] = result; 
        return memo[i];
    }
};
//DP Bottom UP

class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n == 0) return 0;

        vector<int> memo(n+1);

        memo[0] =0;
        memo[1] =nums[0];

        for(int i =1;i<n;i++){

            memo[i+1] = max(memo[i-1] + nums[i],memo[i]);
        }

        return memo[n];
    }

  
};
//DP BOttom Down