class Solution {
public:
    bool isValid(string s) {
        if (s.length() == 0 || s.length() == 1) return false;
        stack<char> stk;
        for (int i=0; i< s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
                continue;
            }
            else if (s[i] == ')' && (stk.empty() || stk.top() != '('))
                return false;
            else if (s[i] == ']' && (stk.empty() || stk.top() != '['))
                return false;
            else if (s[i] == '}' && (stk.empty() || stk.top() != '{'))
                return false;
            stk.pop();
        }
        return stk.size() == 0;
    }
};
