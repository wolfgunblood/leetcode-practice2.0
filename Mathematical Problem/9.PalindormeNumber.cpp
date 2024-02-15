class Solution {
public:
    bool isPalindrome(int x) {
        
        long int rev =0;
        long int temp = x;
        long int d;
        if(temp < 0) return false ;

        while(temp>0){
            d = temp%10;
            rev = rev*10 +d;
            temp=temp/10;
            cout<<d<<" ";  
        }

        if(rev == x) return true;

        return false;
    }
};