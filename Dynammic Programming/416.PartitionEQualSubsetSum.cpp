class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum = 0;
        for(auto num : nums) sum += num;

        if(sum%2) return false;

        unordered_set<int> s;
        s.insert(0);
        int target = sum/2;

        for(int i=0;i<nums.size();i++){

            unordered_set<int> tempset;

            for(auto itr : s){

                if(target == itr + nums[i]) 
                    return true;

                tempset.insert(itr + nums[i]);
                tempset.insert(itr);
            }
            s = tempset;
        }

        return false;
    }
};