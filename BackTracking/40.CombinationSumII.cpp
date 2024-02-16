class Solution {
public:

    void dfs(int start,vector<int>& candidates,int targetSum,vector<vector<int>>& result,vector<int>& curr){
        if(targetSum == 0) 
        {
            result.push_back(curr);
            return ;
        }
        if(targetSum < 0) return ;

        for(int i = start;i<candidates.size();i++){

            if(i > start && candidates[i] == candidates[i-1]) continue;

            curr.push_back(candidates[i]);
            dfs(i+1,candidates,targetSum - candidates[i],result,curr);
            curr.pop_back();
        }
       
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());

        vector<vector<int>> result = {};
        vector<int> curr;
        int start = 0;

        dfs(start,candidates,target,result,curr);

        return result;
    }
};