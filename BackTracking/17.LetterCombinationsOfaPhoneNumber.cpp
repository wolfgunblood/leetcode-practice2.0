class Solution {
public:
        unordered_map<int,string> m={
            {'2' , "abc"},
            {'3' , "def"},
            {'4' , "ghi"},
            {'5' , "jkl"},
            {'6' , "mno"},
            {'7' , "pqrs"},
            {'8' , "tuv"},
            {'9' , "wxyz"},
        };
    vector<string> letterCombinations(string digits) {
        
        if(digits.empty()){
            return {};
        }


        vector<string> result;
        string curr= "";
        dfs(digits,0,result,curr);

        return result;
    }

    void dfs(string digits,int index,vector<string>& result, string& curr){

        // if(index > digits.size()) return ;
        if(index == digits.size() )
        {
            result.push_back(curr);
            return ;
        }
        string str = m[digits[index]];
        for(int i =0;i<str.size();i++){

            curr.push_back(str[i]);
            dfs(digits,index+1,result,curr);
            curr.pop_back();
        }
    }
};