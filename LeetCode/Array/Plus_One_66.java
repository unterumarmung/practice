//LeetCode Link: https://leetcode.com/problems/plus-one/

class Solution {
    private int[] plusOne(int[] digits, int currentIndex) {
        int digit = digits[currentIndex];
        
        if (digit < 9) {

            digit += 1;
            digits[currentIndex] = digit;

        } else if (digit == 9) {

            digit = 0;
            digits[currentIndex] = digit;
            
            if (currentIndex == 0) {
                int[] newDigits = new int[digits.length + 1];
                newDigits[0] = 1;
                System.arraycopy(newDigits, 1, digits, 0, digits.length);
                return newDigits;
            } else {
                return plusOne(digits, currentIndex - 1);
            }

        }
        return digits;
    }
    
    public int[] plusOne(int[] digits) {
        return plusOne(digits, digits.length - 1);
    }
}