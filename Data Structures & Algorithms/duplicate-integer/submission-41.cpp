#include <vector>
#include <cstring>

// 1. Extreme I/O acceleration
static const auto _ = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

// 2. Power-of-two flat hash table allocated statically (no malloc/free overhead)
constexpr int TABLE_SIZE = 262144; // 2^18, large enough to keep load factor low (< 40%)
constexpr int MASK = TABLE_SIZE - 1;
static int table[TABLE_SIZE];
static bool used[TABLE_SIZE];

class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return false;

        // Reset our flat lookup table
        std::memset(used, 0, sizeof(used));

        // Use raw pointer for zero overhead iteration
        const int* data = nums.data();

        for (int i = 0; i < n; ++i) {
            int val = data[i];

            // Murmur3 32-bit finalizer integer hash (super fast bitwise ops)
            unsigned int h = static_cast<unsigned int>(val);
            h ^= h >> 16;
            h *= 0x85ebca6b;
            h ^= h >> 13;
            h *= 0xc2b2ae35;
            h ^= h >> 16;

            int idx = h & MASK;

            // Open addressing: linear probing
            while (used[idx]) {
                if (table[idx] == val) {
                    return true; // Found duplicate
                }
                idx = (idx + 1) & MASK;
            }

            // Insert new value
            used[idx] = true;
            table[idx] = val;
        }

        return false;
    }
};