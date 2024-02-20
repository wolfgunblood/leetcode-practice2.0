class Solution {
public:
    int rob(vector<int>& nums) {

        
        int n = nums.size();
        if(n ==1) return nums[0];

        auto start1 = nums.begin();
        auto end1 =nums.begin() + n-1;
        auto start2 = nums.begin()+1;
        auto end2 =nums.begin() + n;
        vector<int> result1(n-1);
        vector<int> result2(n-1);
        copy(start1,end1,result1.begin());
        copy(start2,end2,result2.begin());
        for(auto itr : result1){
            cout<<itr<<" ";
        }
        cout<<"\n";
        for(auto itr : result2){
            cout<<itr<<" ";
        }
        cout<<"\n";

        vector<int> memo1(n,-1);
        vector<int> memo2(n,-1);

        return max(DP(result1,memo1,n-2),DP(result2,memo2,n-2));
        // int a = DP(result1,memo1,n-2);
        // int b = DP(result2,memo2,n-2);
        // cout<<a<<" "<<b;
        // return max(a,b);
        // return DP(nums,n-1);
    }

    int DP(vector<int>& nums,vector<int>& memo,int i){

        if(i<0) return 0;
        
        if(memo[i] >= 0) return memo[i];
        memo[i] = max(DP(nums,memo,i-2)+nums[i],DP(nums,memo,i-1)); 
        return memo[i];
    }
};