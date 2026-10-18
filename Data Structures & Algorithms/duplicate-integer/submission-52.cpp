class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        bool ans=false;
        int i=0;
        int n=nums.size();
        while(i<n){
            int j=i+1;
            while(j<n){
                if(nums[i]==nums[j]){
                    ans=true;
                }
                j++;
            }
            i++;
        }
        return ans;
    }
};