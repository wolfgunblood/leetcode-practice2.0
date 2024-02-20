class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        
        for(auto c : s){

            if(c == '(' || c == '{' || c == '['){

                stk.push(c);
                continue;
                
            }

            if(!stk.empty() && c == ')' && stk.top() == '(') stk.pop();  
            else if(!stk.empty() && c == '}' && stk.top() == '{') stk.pop(); 
            else if(!stk.empty() && c == ']' && stk.top() == '[') stk.pop();
            else return false;
        }

        if(stk.empty()) return true;

        return false;
    }
};