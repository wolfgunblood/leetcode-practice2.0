class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> hashmap;
        int n = nums.size();
        int ans = 0;
        int preFix[n];
        preFix[0] = nums[0];

        for(int i=1;i<n;i++){
            preFix[i] = nums[i] + preFix[i-1];
        }

        for(int i = 0;i<n;i++){

            if(preFix[i] == k){
                ans++;
            }
            
            if(hashmap.find(preFix[i] - k) !=  hashmap.end())
            {
                ans += hashmap[preFix[i] - k];
            }
            hashmap[preFix[i]]++;
        }

        return ans;   
     
    }
};

// Next Solution

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        map<int,int> hashmap;
        int sum = 0,res = 0;
        hashmap[0]++;
        for(int i =0;i<nums.size();i++)
        {
            sum += nums[i];
            res += hashmap[sum-k];
            hashmap[sum]++;
        }
        
        return res;
        
    }
};