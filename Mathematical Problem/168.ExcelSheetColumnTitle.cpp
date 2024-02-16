class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        int x = columnNumber;
        string result;

        while(x>0)
        {
            x--;
            int curr = x%26;
            x = x/26;
            result.push_back(curr + 'A');
        }

        reverse(result.begin(),result.end());
        return result;
    }
};