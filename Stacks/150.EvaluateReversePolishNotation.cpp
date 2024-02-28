class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> stk;
        for(int i =0;i<tokens.size();i++){

            string token = tokens[i];
            if(token.size() > 1 || isdigit(token[0]))
            {
                stk.push(stoi(token));
                continue;
            }

            int result;
            int b = stk.top();
            stk.pop();
            int a = stk.top();
            stk.pop();

            if(token == "+"){
                result = a+b;
            }else if(token == "-"){
                result = a-b;
            }else if(token == "*"){
                result = a*b;
            }else{
                result = a/b;
            }

            stk.push(result);
        }

        return stk.top();
        
    }
};