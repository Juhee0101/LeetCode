class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = 0;
        int idx = 1;
        
        for (int i=0; i<nums.size(); i++) {
            result += idx - nums[i];
            idx++;
        }
        return result;
    }
};