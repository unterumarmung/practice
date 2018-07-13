//LeetCode link: https://leetcode.com/problems/number-of-1-bits/
int hammingWeight(uint32_t number) {
    int bits_number = 0;
    while (number) {
        bits_number += number & 1;
        number >>= 1;
    }
    return bits_number;
}
