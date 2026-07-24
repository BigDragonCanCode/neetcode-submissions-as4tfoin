class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //numbers wait until see an operator, apply operation on the latest 2 nums
        stack<int> stk;

        for (int i=0; i<tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();

                if (tokens[i] == "+") stk.push(a+b);
                if (tokens[i] == "-") stk.push(a-b);
                if (tokens[i] == "*") stk.push(a*b);
                if (tokens[i] == "/") stk.push(a/b);
            } else {
                stk.push(stoi(tokens[i]));
            }
        }
        return stk.top();
    }
};
