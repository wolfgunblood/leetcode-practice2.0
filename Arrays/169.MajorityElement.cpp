class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int len = nums.size();
        int major = len/2;
        int ans;
        unordered_map<int,int> hashmap;

        for(int i = 0;i<len;i++){

            hashmap[nums[i]]++;
            
            if(hashmap[nums[i]] > major)
            ans = nums[i];
        }

        return ans;
    }
};