class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i) {
            result <<= 1;           // Left shift result to make space
            result |= (n & 1);      // Add last bit of n to result
            n >>= 1;                // Right shift n to process next bit
        }
        return result;
    }
};

