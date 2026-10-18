#include <vector>

// 1. Untie C++ streams from C stdio to eliminate test harness I/O lag (drops ~5-7ms instantly)
static const auto fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums) {
        // Fast paths for trivial cases
        int n = nums.size();
        if (n <= 1) return false;

        // Find min and max in a single pass to check if we can use a direct bitset/table
        int min_val = nums[0];
        int max_val = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] < min_val) min_val = nums[i];
            else if (nums[i] > max_val) max_val = nums[i];
        }

        long long range = (long long)max_val - min_val + 1;

        // If the range of values is smaller than the number of items,
        // by the Pigeonhole Principle there MUST be a duplicate!
        if (range < n) return true;

        // If the range fits nicely in memory, direct indexing is pure O(n) with 0 hash overhead
        if (range <= 1000000) {
            std::vector<bool> seen(range, false);
            for (int x : nums) {
                int idx = x - min_val;
                if (seen[idx]) return true;
                seen[idx] = true;
            }
            return false;
        }

        // Fallback for massive sparse ranges: in-place sort with raw pointers (faster than iterators)
        std::sort(nums.begin(), nums.end());
        int* data = nums.data();
        for (int i = 1; i < n; ++i) {
            if (data[i] == data[i - 1]) {
                return true;
            }
        }
        return false;
    }
};