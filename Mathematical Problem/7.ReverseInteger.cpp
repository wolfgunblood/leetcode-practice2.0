class Solution {
public:
    int reverse(long int x) {
        
        int rev=0;
        
        while(x!=0)
        {
            int pop=x%10;
            x=x/10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        cout<<rev;
        
        return rev;
        
    }
};