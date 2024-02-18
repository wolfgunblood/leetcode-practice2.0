class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> ans;

        for(int i =0;i<=n;i++){

            int sum = 0;
            int num = i;

            while(num > 0 ){
                sum += num%2;
                num = num/2;
            }

            ans.push_back(sum);
        }

        return ans;
    }
};

//dp
class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> dp(n+1,0);

        for(int i =0 ; i<=n ; i++){

            dp[i] = dp[i/2] + i%2;
        }

        return dp;
    }
};