class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> arr;
        for (int num:nums) arr.insert(num);
        if (arr.size() < nums.size()) return true;
        else return false;
    }
};