class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int minLen = INT_MAX; 
        string result = "";

        for(int i = 0;i<strs.size();i++)
        {
            int n = strs[i].length();
            minLen = min(minLen,n);
        }

        for(int i =0;i<minLen;i++)
        {
            char temp = strs[0][i];
            bool flag = true;

            for(int j = 1;j<strs.size();j++)
            {
                if(temp != strs[j][i]){
                    flag = false;
                    break;
                }
            }
            if(flag)
            result = result + temp;
            else
            break;
        }

        return result;
    }
};

//Longest Common Prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
       sort(strs.begin(),strs.end());

       int n = strs.size();
        string ans = "";
       string first = strs[0];
       string last = strs[n-1];

       for(int i = 0 ;i<min(first.length(),last.length());i++)
       {
           if(first[i] != last[i]){
               return ans;
           }
           ans += first[i];
       }

       return ans;
    }
};