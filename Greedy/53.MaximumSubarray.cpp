class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        // int prefixSum = 0;
        int sumSoFar = 0;
        int maxSum = nums[0];

        for(int i=0;i<nums.size();i++){

            sumSoFar +=nums[i];
            maxSum = max(sumSoFar,maxSum);
            sumSoFar = max(sumSoFar,0);
        }

        return maxSum;

    }
};