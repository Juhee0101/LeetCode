class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxVol=0;
        int left = 0;
        int right = height.size()-1;

        while (left < right) {
            int vol = (right - left) * min(height[left], height[right]);
            maxVol = max(vol, maxVol);

            if (height[left] < height[right]) {
                while (left < right && height[left] >= height[left+1]){
                    left++;
                }
                left++;
            }
            else {
                while (left < right && height[right] >= height[right-1]) {
                    right--;
                }
                right--;
            }
        }
        return maxVol;
    }
};