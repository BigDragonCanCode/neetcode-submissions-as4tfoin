class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n > 0) {
            if (n & 1 == 1) // check last bit
                count++;
            n = n >> 1; //shift n to the right for 1 bit
        }
        return count;
    }
};
