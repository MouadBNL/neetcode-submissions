class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> freq;

        for(int i: nums) {
            if(freq.contains(i)) return true;
            freq.insert_or_assign(i, true);
        }

        return false;
    }
};