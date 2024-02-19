class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        unordered_map<int,int> hashmap;
        vector<int> result;
        for(auto itr : nums) hashmap[itr]++;

        for(auto itr : hashmap) {
            if(itr.second == 2) result.push_back(itr.first);
        }

        return result;
    }
};