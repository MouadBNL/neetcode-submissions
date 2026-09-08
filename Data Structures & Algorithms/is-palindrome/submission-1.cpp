class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n-1;
        
        while(i < j) {
            while(i < j && !isAlphaNum(s[i])) i++;
            while(i < j && !isAlphaNum(s[j])) j--;
            if(tolower(s[i]) != tolower(s[j])) return false;
            i++; j--;
        }

        return true;
    }


    bool isAlphaNum(char c) {
        return (c >= '0' && c <= '9') 
            || (c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z');
    }
};
