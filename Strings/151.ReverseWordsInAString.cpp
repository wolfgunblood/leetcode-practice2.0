class Solution {
public:
    string reverseWords(string s) {
        
        vector<string> res;
        s = s + " ";
        string temp = "";

        for(int i = 0;i<s.length();i++){
            
            if(s[i] != ' ')
            {
                temp = temp+s[i];
            }
            if(s[i] == ' ' && temp.length()>0)
            {
                cout<<temp<<" ";
                res.push_back(temp);
                temp = "";
            }
        }

        string output = "";

        for(int i = res.size() - 1;i>0;i-- )
        output = output + res[i] + " ";

        return output + res[0];

    }
};