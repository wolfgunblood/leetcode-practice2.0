class Solution {
public:
    int singleNumber(vector<int>& nums) {

        unordered_map<int,int> hashmap;
        int result;
        for(auto itr : nums){
            hashmap[itr]++;
        }

        for(auto itr : hashmap){
            if(itr.second == 1){
                result = itr.first;
                break;
            }
        }

        return result;
        
    }
};