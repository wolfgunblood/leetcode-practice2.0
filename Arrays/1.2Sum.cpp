class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> result;
        unordered_map<int,int> hashmap;

        for(int i =0;i<nums.size();i++){

            if(hashmap.find(target - nums[i]) == hashmap.end()){
                hashmap[nums[i]] = i;
            }else{
                result.push_back(hashmap[target - nums[i]]);
                result.push_back(i);
                break;
            }
        }

        return result;

    }
};