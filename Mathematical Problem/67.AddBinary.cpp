class Solution {
public:
    string addBinary(string a, string b) {

        string result;
        int carry =0;
        int i = a.length()-1;
        int j = b.length()-1;

        while(carry || i>=0 || j>=0){

            if(i>=0){
                carry+= a[i--] - '0';
            }
            if(j>=0){
                carry+=b[j--] - '0';
            }

            result.push_back(carry%2 +'0');
            carry=carry/2;
        }

        reverse(result.begin(),result.end());

        return result;
        
    }
};