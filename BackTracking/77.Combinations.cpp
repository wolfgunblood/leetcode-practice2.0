class Solution {
public:
    void dfs(int start,int n,int k,vector<vector<int>>& ans,vector<int>& curr){

        if(curr.size() == k){
            ans.push_back(curr);
            return ;
        }

        for(int i = start;i<=n;i++){

            curr.push_back(i);
            dfs(i+1,n,k,ans,curr);
            curr.pop_back();
        }

    }

    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> ans = {};
        vector<int> curr;

        dfs(1,n,k,ans,curr);

        return ans;
    }
};