class Solution {
public:
    void dfs(vector<int>& nums,int start,vector<vector<int>>& result,vector<int>& curr){

        result.push_back(curr);
        for(auto itr : curr) cout<<itr<<"-";
        cout<<"\n";

        for(int i=start;i<nums.size();i++){
            curr.push_back(nums[i]);
            dfs(nums,i+1,result,curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> result;
        vector<int> curr;
        int start = 0;

        dfs(nums,0,result,curr);

        return result;
    }
};