class Solution {
public:
    bool isValid(string s) {
        vector<char> stk;
        for(char c:s) {
            if(c == '(' || c == '{' || c == '[') {
                stk.push_back(c);
                continue;
            }

            if(stk.empty()) return false;

            if(c == ')' && stk.back() != '(') return false;
            if(c == '}' && stk.back() != '{') return false;
            if(c == ']' && stk.back() != '[') return false;

            stk.pop_back();
        }

        if(!stk.empty()) return false;

        return true;
    }
};
