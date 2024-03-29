class Solution {
public:
    string longestPalindrome(string s) {
        
        int maxStart = 0;
        int maxLength = 1;

        for(int i =0;i<s.size()-1;i++) //for(int i =0;i<s.size()-1;i++)
        {
            middleInOut(s,i,i,maxStart,maxLength);
            middleInOut(s,i,i+1,maxStart,maxLength);
        }
         return s.substr(maxStart,maxLength);
        }
    

    void middleInOut(string s,int i,int j,int& maxStart,int& maxLength){

        while(i>=0 && j<=s.size() - 1 && s[i] == s[j]){

            i--;
            j++;
        }

        if(j-i-1 >maxLength){
            maxStart =i+1;
            maxLength =j-i-1;
        }
    }
};