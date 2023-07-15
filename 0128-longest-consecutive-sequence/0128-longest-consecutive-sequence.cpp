class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int vectorSize = nums.size();
        if(vectorSize==0 | vectorSize==1) return vectorSize;

        sort(nums.begin(), nums.end());
        int maxLen = 1;
        int len = 1;

        for (int i=0; i<vectorSize-1; i++) {
            if (nums[i+1] - nums[i] == 1){
                len++;
                if (len>maxLen) maxLen = len;
            }
            else if (nums[i+1] - nums[i] == 0) len=len;
            else len = 1;
        }
        return maxLen;        
    }
};