class Solution{
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result=0;
        uint32_t remain=0;
        int cnt = 31;

        while (cnt >= 0) {
            remain = n % 2;
            n = n / 2;
            result = result * 2 + remain;
            cnt--;
        }
        return result;
    }
};