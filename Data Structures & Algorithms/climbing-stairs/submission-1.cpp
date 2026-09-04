class Solution {
public:
    unordered_map<int, int> cache;
    int climbStairs(int n) {
        if(n <= 1) return 1;
        if(cache.contains(n)) return cache[n];

        int ans = climbStairs(n-1) + climbStairs(n-2);

        cache.emplace(n, ans);

        return ans;
    }
};
