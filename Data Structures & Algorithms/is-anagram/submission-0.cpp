class Solution {
public:
    bool isAnagram(string s, string t) {
        constexpr int cnt = CHAR_MAX;
        int freqs[cnt] = {0}, freqt[cnt] = {0};


        for(char c: s) freqs[c]++;
        for(char c: t) freqt[c]++;


        for(int i = 0; i < cnt; i++) {
            if(freqs[i] != freqt[i]) return false;
        }

        return true;
    }
};
