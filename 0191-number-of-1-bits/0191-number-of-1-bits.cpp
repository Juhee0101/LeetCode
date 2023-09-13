class Solution {
public:
    int hammingWeight(uint32_t n) {
        int remain = 0;

        while (n != 0) {
            remain = remain + n % 2;
            n = n / 2;
        }
        return remain;
    }
};