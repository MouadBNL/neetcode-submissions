class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ans;


        for(string &s: strs) {
            string key = s;
            std::sort(key.begin(), key.end());
            auto [it, inserted] = ans.try_emplace(key);
            it->second.push_back(s);
        }
        
        vector<vector<string>> res;

        for (const auto& [key, value] : ans) {
            res.push_back(value);
        }

        return res;
    }
};
