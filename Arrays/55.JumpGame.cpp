class Solution {
public:
    bool canJump(vector<int>& nums) {
        
       int gas = 0;

       for(auto itr : nums){

           if(gas < 0) return false;

           else if( gas < itr) gas = itr;

           gas -= 1;
       }

       return true;
    }
};