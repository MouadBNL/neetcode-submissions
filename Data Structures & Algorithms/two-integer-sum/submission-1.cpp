class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> exist;

        for(int i = 0; i < nums.size(); i++) {

            if(exist.contains(target-nums[i])) {
                return {exist[target-nums[i]], i};
            }
            exist.try_emplace(nums[i], i);
        }

        return {};
    }
};
