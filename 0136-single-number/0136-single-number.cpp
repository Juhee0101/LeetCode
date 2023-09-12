class Solution {
public:
    int singleNumber(vector<int>& nums) {
        bitset<32> result(0);

        for (int i=0; i<nums.size(); i++) {
            bitset<32> numBit(nums[i]);
            result ^= numBit;
        }

        return static_cast<int>(result.to_ulong());
    }
};