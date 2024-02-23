class Solution {
public:

    void dfs(int start,vector<int>& candidates,int targetSum,vector<vector<int>>& result,vector<int>& curr){

        if(targetSum < 0) return;
        if(targetSum == 0) {
            result.push_back(curr);
            return ;
        }

        for(int i =start;i<candidates.size();i++){

            curr.push_back(candidates[i]);
            dfs(i,candidates,targetSum-candidates[i],result,curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> result;
        vector<int> curr;

        dfs(0,candidates,target,result,curr);

        return result;
    }
};