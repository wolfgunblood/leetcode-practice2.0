class Solution {
public:

    void dfs(vector<int>& nums,vector<vector<int>>& ans,vector<int>& curr,vector<bool>& visited){

        if(curr.size() == nums.size())
        {
            ans.push_back(curr);
            return ;
        }

        for(int i = 0;i<nums.size();i++){

            if(visited[i] || i>0 && nums[i] == nums[i-1] && !visited[i-1]) continue;

            visited[i] =true;
            curr.push_back(nums[i]);
            dfs(nums,ans,curr,visited);
            curr.pop_back();
            visited[i] =false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<bool> visited(nums.size(),0);
        vector<vector<int>> ans;
        vector<int> curr;
        int start =0;

        dfs(nums,ans,curr,visited);
        return ans;
    }
};