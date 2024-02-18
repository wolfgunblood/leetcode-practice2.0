class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxi = INT_MIN;
        int n = nums.size();
        int prod1 = 1;
        for(int i = 0;i<n;i++){

            prod1 = prod1*nums[i];
            maxi = max(prod1,maxi);

            if(prod1 == 0){
                prod1 = 1;
            }
        }
        prod1 = 1;

        for(int i =n-1;i>=0;i--){

            prod1 = prod1*nums[i];
            maxi = max(prod1,maxi);

            if(prod1 == 0){
                prod1 = 1 ;
            }
        }
        
        return maxi;
    }
};