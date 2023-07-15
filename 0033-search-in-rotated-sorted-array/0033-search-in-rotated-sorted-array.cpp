class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, mid;

        while (left <= right) {
            mid = (left + right) / 2;
            if (target == nums[mid]) return mid;
            else if (target > nums[mid]) {
                if (target > nums[right] && nums[right] >= nums[mid]) right = mid-1;
                else left = mid+1;
            } else {
                if (target < nums[left] && nums[left] <= nums[mid]) left = mid+1;
                else right = mid-1;
            }
        }
        return -1;        
    }
};