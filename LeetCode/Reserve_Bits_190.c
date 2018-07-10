//LeetCode link: https://leetcode.com/problems/reverse-bits/
uint32_t reverseBits(uint32_t number) {
    uint32_t result = 1;

    for(int i = 0; i < 32; ++i)
    {
        uint_least8_t bit = number % 2; //contains i-th bit of the number
        number >>= 1; //move the number to rigth for one bit
        result <<= 1; //move the result to left for one bit
        result += bit; 
    }
    return result;
}