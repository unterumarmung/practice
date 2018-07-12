//LeetCode Link: https://leetcode.com/problems/valid-palindrome/
class Solution {
    private boolean isThereAnyAlphanumeric(String str)
    {
        int size = str.length();
        for (int i = 0; i < size; ++i){
            if (isalnum(str.charAt(i))) return true;
        }
        return false;
    }
    private boolean isalnum(char c){
        return Character.isLetter(c) || Character.isDigit(c);
    }
    public boolean isPalindrome(String str) {
        int strLength = str.length();
    
        if (strLength == 0 || strLength == 1 || !isThereAnyAlphanumeric(str)) { return true; }
    
        int begin = 0;
        int end = strLength - 1;
        boolean good = true;

        while (begin < strLength && end >= 0 && good)
        {
            while ( begin < strLength && !isalnum(str.charAt(begin)) ) { begin += 1; }
            while ( end >= 0 && !isalnum(str.charAt(end)) ) { end -= 1; }
            
            if(begin >= strLength || end < 0);
            else {
                char beginChar = Character.toLowerCase(str.charAt(begin));
                char endChar = Character.toLowerCase(str.charAt(end));

                if ( beginChar != endChar ) { good = false; }

                begin += 1;
                end -= 1;
            }
        }

        return good;
    }
}