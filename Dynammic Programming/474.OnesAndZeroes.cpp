//Recursion
class Solution {
public:

    int DP(vector<pair<int,int>> &a,int index,int nZeroes,int nOnes){

        int n =a.size();

        if(index == n || (nZeroes == 0 && nOnes == 0)) return 0;

        if(a[index].first > nOnes || a[index].second > nZeroes)
            return DP(a,index+1,nZeroes,nOnes);
        
        int include = 1 + DP(a,index+1,nZeroes - a[index].second,nOnes - a[index].first);
        int exclude = DP(a,index + 1,nZeroes,nOnes);

        return max(include,exclude);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<pair<int,int>> a;

        for(auto itr : strs){

            int zero = 0,one =0;
            for(auto j : itr)
                (j == '1') ? one++ : zero++;

            a.push_back({one,zero});
        }

        int ans  = DP(a,0,m,n);

        return ans;
    }
};
//memozization top-down
class Solution {
public:
    int dp[601][101][101] = {};

    int DP(vector<pair<int,int>> &a,int index,int nZeroes,int nOnes){

        int n =a.size();

        if(index == n || (nZeroes == 0 && nOnes == 0)) return 0;

        if(dp[index][nOnes][nZeroes] != -1) return dp[index][nOnes][nZeroes];

        if(a[index].first > nOnes || a[index].second > nZeroes)
            return dp[index][nOnes][nZeroes] = DP(a,index+1,nZeroes,nOnes);
        
        int include = 1 + DP(a,index+1,nZeroes - a[index].second,nOnes - a[index].first);
        int exclude = DP(a,index + 1,nZeroes,nOnes);

        return dp[index][nOnes][nZeroes] = max(include,exclude);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<pair<int,int>> a;

        memset(dp,-1,sizeof(dp));

        for(auto itr : strs){

            int zero = 0,one =0;
            for(auto j : itr)
                (j == '1') ? one++ : zero++;

            a.push_back({one,zero});
        }

        int ans  = DP(a,0,m,n);

        return ans;
    }
};

//bottom up tabulation
int findMaxForm(vector<string>& strs, int zeros, int ones) 
    {
        int i,j,k,l,p=strs.size();
        vector<vector<int>> dp(zeros+1 , vector<int>(ones+1));
        
        for(auto &s:strs)
        {
            int currOnes = count(s.begin(),s.end(),'1');
            int currZeros = s.size()-currOnes;
            
            for(j=ones;j>=currOnes;j--)
            {
                for(i=zeros;i>=currZeros;i--)
                {
                    dp[i][j] = max(dp[i][j],1+dp[i-currZeros][j-currOnes]);
                }
            }
        }
        return dp[zeros][ones];
    }