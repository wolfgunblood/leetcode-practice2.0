class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int maxSize=0,i=0,j=0;
    unordered_set<int> chars;
    while(j<s.size()){

        while(chars.find(s[j]) != chars.end()){
            chars.erase(s[i]);
            i++;
        }
        maxSize = max(maxSize,j-i+1);
        chars.insert(s[j]);
        j++;
    }
    return maxSize;
    
    }
};