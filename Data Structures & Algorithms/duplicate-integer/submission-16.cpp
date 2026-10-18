class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    int n = nums.size();
    unordered_set<int> sett;
    for(auto num:nums){
        sett.insert(num);
    }
    if(sett.size() < nums.size()){
        return true;
    }
    else return false;
    }
};