class Solution {
public:
    void dfs(int start,vector<int>& nums,vector<vector<int>>& result,vector<int>& curr){

        result.push_back(curr);

        for(int i = start;i<nums.size();i++){

            if(i>start && nums[i] == nums[i-1]) continue ;

            curr.push_back(nums[i]);
            dfs(i+1,nums,result,curr);
            curr.pop_back();
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());

        vector<vector<int>> result;
        vector<int> curr;
        int start =0;

        dfs(start,nums,result,curr);

        return result;    
    }
};