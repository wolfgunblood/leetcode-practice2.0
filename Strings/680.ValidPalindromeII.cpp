class Solution {
public:
    bool palin(string s,int low,int high){

        while(low < high)
        {
            if(s[low] != s[high]){
                return false;
            }
            else{
                low++;
                high--;
            }
        }

        return true;
    }
    
    bool validPalindrome(string s) {
        
        int low = 0,high = s.length() - 1;

        while(low <= high){

            if(s[low] != s[high]){
                
                return palin(s,low+1,high) || palin(s,low,high-1);
            }else{
            low++;
            high--;
            }
        }

        return true; 
    }
};