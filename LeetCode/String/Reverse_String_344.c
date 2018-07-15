//LeetCode Link: https://leetcode.com/problems/reverse-string/
/*
Complexity analysis:
* Time: O(n)
* Space: O(1)
*/
void swap_chars_in_string(char* str, int first_index, int second_index) {
    char temp_char = str[first_index];
    str[first_index] = str[second_index];
    str[second_index] = temp_char;
}

char* reverseString(char* str) {
    const int str_length = strlen(str);
    
    for (int i = 0; i < str_length / 2; ++i) {
        swap_chars_in_string(str, i, str_length - i - 1);
    }
    
    return str;
}