class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        long int res1 = nums[n-1]*nums[n-2]*nums[n-3];
        long int res2 = nums[0]*nums[1]*nums[n-1];

        return res1 > res2 ? res1 : res2;
        
    }
};