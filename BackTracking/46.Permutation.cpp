class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> result;
        dfs(nums,0,result);

        return result;
    }

    void dfs(vector<int>& nums,int start,vector<vector<int>>& result){
        
      
        
        if(start == nums.size()) {
            result.push_back(nums);
            return;
        }

        for(int i =start;i<nums.size();i++){
            swap(nums[start],nums[i]);
            dfs(nums,start+1,result);
            swap(nums[i],nums[start]);
        }
    }
};
//BFS
class Solution {
public:

    void dfs(vector<int>& nums,vector<vector<int>>& result,vector<int>& curr,vector<bool>& visited){

        if(curr.size() == nums.size())
        {
            result.push_back(curr);
            return ;
        }
        for(int i = 0;i<nums.size();i++){
            
            if(!visited[i]){
                visited[i] = true;
                curr.push_back(nums[i]);
                dfs(nums,result,curr,visited);
                visited[i] = false;
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        
       vector<vector<int>> result;
       vector<int> curr;
       vector<bool> visited(nums.size(),false);

       dfs(nums,result,curr,visited);

       return result;
    }
};