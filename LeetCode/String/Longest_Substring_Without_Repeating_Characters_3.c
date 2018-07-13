//LeetCode Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
#define CHARACTERS_COUNT 128

int max(int val1, int val2) {
    return (val1 > val2) ? val1 : val2;
}

/*
1st solution.
Complexity analysis:
* Time: O(N²) - worst case, O(N * logN) - amortized
* Memory: O(1) - always
*/
int lengthOfLongestSubstring(char* str) {
    const int str_length = strlen(str); //length of string
    
    if (str_length == 0) return 0;
    if (str_length == 1) return 1;
    
    int max_substring_length = 1; //length of the longest substring without repeating characters
    int current_begin = 0; 
    
    for (int char_index = 1; char_index < str_length; ++char_index) {
        char current_char = str[char_index];
        int current_length; //length of the longest required substring for current character
        
        for (int i = current_begin; i < char_index; ++i) {
            if (str[i] == current_char) { 
                current_begin = i + 1; 
            }
        }
        
        current_length = char_index - current_begin + 1;
        max_substring_length = max(max_substring_length, current_length);
    }
    
    return max_substring_length;
}

/* 
2nd solution.
Complexity analysis:
* Time: O(N) - always
* Memory: O(1) - always
*/
int lengthOfLongestSubstring(char* str) {
    const int str_length = strlen(str); //length of string
    
    if (str_length == 0) return 0;
    if (str_length == 1) return 1; 
    
    int max_substring_length = 1; //length of the longest substring without repeating characters
    int current_begin = 0; 
    
    int chars_index[CHARACTERS_COUNT]; //last occurrence of i-th char in ASCII
    memset(chars_index, -1, sizeof(int) * CHARACTERS_COUNT);
    
    chars_index[str[0]] = 0;
    for (int char_index = 1; char_index < str_length; ++char_index) {
        char current_char = str[char_index];
        int current_length; //length of the longest required substring for current character

        if (chars_index[current_char] == -1) { 
            chars_index[current_char] = char_index; 
        } else {
            if (chars_index[current_char] + 1 > current_begin) { current_begin = chars_index[current_char] + 1; }
            chars_index[current_char] = char_index;
        }
        
        current_length = char_index - current_begin + 1;
        max_substring_length = max(max_substring_length, current_length);
    }
    
    return max_substring_length;
}
